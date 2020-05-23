#include "game.h"

#include <QDebug>

Game::Game(QWidget *parent) : Widget(parent)
{
    QHBoxLayout* _layout = new QHBoxLayout();

    _database = new Database();

    _players.insert(0, new Player("darkred"));
    _players.insert(1, new Player("darkblue"));

    _currentplayer = 0;
    _buildingcreated = false;

    _map = new Map(this);
    for(int i = 0; i < _map->GetSize().height(); ++i){
        for(int j = 0; j < _map->GetSize().width(); ++j){
            _database->Register(_map->GetTile(i, j));
            _database->Register(_map->GetTile(i, j)->GetArmy());
            connect(_map->GetTile(i, j), &Tile::clicked, this, &Game::TilePressed);
        }
    }

    //prepare demo game:

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            _map->GetTile(i,j)->SetOwner(_players[0]);

    _map->GetTile(4, 4)->SetOwner(nullptr);

    for(int i = 9; i > 4; --i)
        for(int j = 9; j > 4; --j)
            _map->GetTile(i,j)->SetOwner(_players[1]);

    _map->GetTile(5, 5)->SetOwner(nullptr);

    _map->GetTile(3, 3)->SetBuilding(CastleType);
    _database->Register(_map->GetTile(3, 3)->GetBuilding());

    _map->GetTile(6, 6)->SetBuilding(CastleType);
    _database->Register(_map->GetTile(6, 6)->GetBuilding());

    _map->GetTile(1, 3)->SetBuilding(BarracksType);
    _database->Register(_map->GetTile(1, 3)->GetBuilding());

    _map->GetTile(3, 1)->SetBuilding(BarracksType);
    _database->Register(_map->GetTile(3, 1)->GetBuilding());

    _map->GetTile(8, 6)->SetBuilding(BarracksType);
    _database->Register(_map->GetTile(8, 6)->GetBuilding());

    _map->GetTile(6, 8)->SetBuilding(BarracksType);
    _database->Register(_map->GetTile(6, 8)->GetBuilding());

    _map->GetTile(3, 4)->GetArmy()->AddUnit(new Swordsman());
    _map->GetTile(3, 4)->GetArmy()->AddUnit(new Swordsman());
    _map->GetTile(4, 3)->GetArmy()->AddUnit(new Swordsman());
    _map->GetTile(4, 3)->GetArmy()->AddUnit(new Swordsman());

    _map->GetTile(6, 5)->GetArmy()->AddUnit(new Swordsman());
    _map->GetTile(6, 5)->GetArmy()->AddUnit(new Swordsman());
    _map->GetTile(5, 6)->GetArmy()->AddUnit(new Swordsman());
    _map->GetTile(5, 6)->GetArmy()->AddUnit(new Swordsman());

    _map->GetTile(2, 4)->GetArmy()->AddUnit(new Horseman());
    _map->GetTile(4, 2)->GetArmy()->AddUnit(new Horseman());

    _map->GetTile(7, 5)->GetArmy()->AddUnit(new Horseman());
    _map->GetTile(5, 7)->GetArmy()->AddUnit(new Horseman());

    _map->GetTile(2, 3)->GetArmy()->AddUnit(new Archer());
    _map->GetTile(3, 2)->GetArmy()->AddUnit(new Archer());

    _map->GetTile(6, 7)->GetArmy()->AddUnit(new Archer());
    _map->GetTile(7, 6)->GetArmy()->AddUnit(new Archer());

    _map->UnhighlightAll();

    _actionfield = new ActionField(this);
    AddButton("next turn", 0, "Следующий ход");

    _layout->addWidget(_map);
    _layout->addWidget(_actionfield);
    setLayout(_layout);
    setStyleSheet("background-color: " + _players[_currentplayer]->GetColor() + ";");
    _map->setMaximumWidth(_map->height());

    _mapstate = MapState::WaitingTileClick;
    _highlighted = nullptr;
}

Game::~Game(){
    if(_map != nullptr)
        delete _map;
    for(auto player: _players)
        delete player;
    if(_actionfield != nullptr)
        delete _actionfield;
}

Map* Game::GetMap(){
    return _map;
}

void Game::AddButton(QString actionname, int sender, QString buttonname, QVector<int> params){
    Button* button = new Button();
    Action action(sender, actionname, params);
    button->SetAction(action);
    button->setText(buttonname);
    connect(button, &Button::clicked, this, &Game::ActionButtonPressed);
    _actionfield->AddButton(button);
}

void Game::CheckWin(){
    if(_map->GetTile(7,7)->GetOwner() == _map->GetTile(2, 2)->GetOwner()){
        QMessageBox mbox;
        mbox.setWindowTitle("Победа!");
        if(_map->GetTile(7,7)->GetOwner()->GetColor() == "darkred") mbox.setText("Красный игрок победил");
        else mbox.setText("Синий игрок победил");
        mbox.exec();
        close();
    }
}

void Game::HandleAction(const Action& action){
    if(action.name == "next turn"){
        _map->TileTick();
        _currentplayer = _currentplayer ^ 1;
        _buildingcreated = false;
        setStyleSheet("background-color: " + _players[_currentplayer]->GetColor() + ";");
    }
    else if(action.name == "purge"){
        _actionfield->Purge();
        _mapstate = MapState::WaitingTileClick;
        if(_highlighted) _map->UnhighlightAll();
        _highlighted = nullptr;
    }
    else if(action.name == "back"){
        if(action.sender != 0){
            _map->UnhighlightAll();
        }
        _actionfield->Pop();
        if(_mapstate == MapState::WaitingTargetClick){
            _mapstate = MapState::Disabled;
            _map->Highlight(_highlighted);
        }
        if(_actionfield->IsEmpty()) _mapstate = MapState::WaitingTileClick;
    }
    else if(action.name == "browse"){
        int id = action.sender;
        Object* object = _database->GetById(id);
        QVector<QString> actions = object->GetPossibleActions();

        _actionfield->NewMenu();

        for(int i = 0; i < actions.size(); ++i){
            AddButton(actions[i], id, Action::Name(actions[i]));
        }

        AddButton("back", 0, "Назад");
    }
    else if(action.name == "browse create building"){
        _actionfield->NewMenu();
        AddButton("create building", action.sender, "Создать казармы", QVector<int>(1, 1));
        AddButton("create building", action.sender, "Создать форт", QVector<int>(1, 2));
        AddButton("create building", action.sender, "Создать окоп", QVector<int>(1, 3));
        AddButton("back", 0, "Назад");
    }
    else if(action.name == "create building"){
        _buildingcreated = true;
        Tile* tile = dynamic_cast<Tile*>(_database->GetById(action.sender));
        int concrete = action.params[0];
        if(concrete == 1){
            tile->SetBuilding(BarracksType);
        }
        if(concrete == 2){
            tile->SetBuilding(FortType);
        }
        if(concrete == 3){
            tile->SetBuilding(MineType);
        }
        _database->Register(tile->GetBuilding());
        Action naction(0, "purge");
        HandleAction(naction);
    }
    else if(action.name == "browse create unit"){
        _actionfield->NewMenu();
        AddButton("create unit", action.sender, "Создать мечника", QVector<int>(1, 1));
        AddButton("create unit", action.sender, "Создать лучника", QVector<int>(1, 2));
        AddButton("create unit", action.sender, "Создать всадника", QVector<int>(1, 3));
        AddButton("back", 0, "Назад");
    }
    else if(action.name == "army move"){
        _mapstate = MapState::WaitingTargetClick;
        _actionfield->NewMenu();
        _highlighted->DrawDisabled();
        int tile_x = _highlighted->GetX();
        int tile_y = _highlighted->GetY();
        for(int i = 0; i < _map->GetSize().height(); ++i)
            for(int j = 0; j < _map->GetSize().width(); ++j)
                if(
                        std::abs(i - tile_x) + std::abs(j - tile_y) == 1 &&
                        _highlighted->GetOwner() == _players[_currentplayer] &&
                        _map->GetTile(i, j)->IsArmyEmpty()
                        )
                {
                    _map->GetTile(i, j)->DrawEnabled();
                }
        _lastaction = action;
        AddButton("back", 0, "Назад");
    }
    else if(action.name == "army attack"){
        _mapstate = MapState::WaitingTargetClick;
        _actionfield->NewMenu();
        _highlighted->DrawDisabled();
        int tile_x = _highlighted->GetX();
        int tile_y = _highlighted->GetY();
        for(int i = 0; i < _map->GetSize().height(); ++i)
            for(int j = 0; j < _map->GetSize().width(); ++j)
                if(
                        std::abs(i - tile_x) + std::abs(j - tile_y) == 1 &&
                        _highlighted->GetOwner() == _players[_currentplayer] &&
                        _map->GetTile(i, j)->GetOwner() == _players[_currentplayer ^ 1] &&
                        !_map->GetTile(i, j)->GetArmy()->IsEmpty()
                        )
                {
                    _map->GetTile(i, j)->DrawEnabled();
                }
        _lastaction = action;
        AddButton("back", 0, "Назад");
    }
    else if(action.name == "browse units"){
        _actionfield->NewMenu();
        Army* army = _highlighted->GetArmy();
        for(int i = 0; i < army->GetUnits().size(); ++i){
            _database->Register(army->GetUnits()[i]);
            if(!army->GetUnits()[i]->CanAct()) continue;
            if(army->GetUnits()[i]->GetType() == 0){
                AddButton("browse", army->GetUnits()[i]->id, "Лучник");
            }
            if(army->GetUnits()[i]->GetType() == 1){
                AddButton("browse", army->GetUnits()[i]->id, "Всадник");
            }
            if(army->GetUnits()[i]->GetType() == 2){
                AddButton("browse", army->GetUnits()[i]->id, "Мечник");
            }
        }
        AddButton("back", 0, "Назад");
    }
    else if(action.name == "move"){
        _mapstate = MapState::WaitingTargetClick;
        _actionfield->NewMenu();
        _highlighted->DrawDisabled();
        int tile_x = _highlighted->GetX();
        int tile_y = _highlighted->GetY();
        for(int i = 0; i < _map->GetSize().height(); ++i)
            for(int j = 0; j < _map->GetSize().width(); ++j)
                if(
                        std::abs(i - tile_x) + std::abs(j - tile_y) > 0 &&
                        std::abs(i - tile_x) + std::abs(j - tile_y) <= dynamic_cast<Unit*>(_database->GetById(action.sender))->GetActionPoints() &&
                        _highlighted->GetOwner() == _players[_currentplayer] &&
                        (_map->GetTile(i, j)->IsArmyEmpty() || _map->GetTile(i, j)->GetOwner() != _players[_currentplayer ^ 1])
                        )
                {
                    _map->GetTile(i, j)->DrawEnabled();
                }
        _lastaction = action;
        AddButton("back", 0, "Назад");
    }
    else if(action.name == "attack"){
        _mapstate = MapState::WaitingTargetClick;
        _actionfield->NewMenu();
        _highlighted->DrawDisabled();
        int tile_x = _highlighted->GetX();
        int tile_y = _highlighted->GetY();
        for(int i = 0; i < _map->GetSize().height(); ++i)
            for(int j = 0; j < _map->GetSize().width(); ++j)
                if(
                        std::abs(i - tile_x) + std::abs(j - tile_y) == 1 &&
                        _highlighted->GetOwner() == _players[_currentplayer] &&
                        _map->GetTile(i, j)->GetOwner() == _players[_currentplayer ^ 1] &&
                        !_map->GetTile(i, j)->GetArmy()->IsEmpty()
                        )
                {
                    _map->GetTile(i, j)->DrawEnabled();
                }
        _lastaction = action;
        AddButton("back", 0, "Назад");
    }
    else if(action.name == "shoot"){
        _mapstate = MapState::WaitingTargetClick;
        _actionfield->NewMenu();
        _highlighted->DrawDisabled();
        int tile_x = _highlighted->GetX();
        int tile_y = _highlighted->GetY();
        for(int i = 0; i < _map->GetSize().height(); ++i)
            for(int j = 0; j < _map->GetSize().width(); ++j)
                if(
                        std::abs(i - tile_x) + std::abs(j - tile_y) > 0  &&
                        std::abs(i - tile_x) + std::abs(j - tile_y) <= 2  &&
                        _highlighted->GetOwner() == _players[_currentplayer] &&
                        _map->GetTile(i, j)->GetOwner() == _players[_currentplayer ^ 1] &&
                        !_map->GetTile(i, j)->GetArmy()->IsEmpty()
                        )
                {
                    _map->GetTile(i, j)->DrawEnabled();
                }
        _lastaction = action;
        AddButton("back", 0, "Назад");
    }
    else HandleAction(_database->GetById(action.sender)->HandleAction(action));
}

void Game::ActionButtonPressed(){
    Button* clickedButton = qobject_cast<Button*>(sender());
    Action action = clickedButton->GetAction();
    HandleAction(action);
}

void Game::TilePressed(){
    Tile* clickedtile = qobject_cast<Tile*>(sender());
    if(!clickedtile->IsEnabled()) return;
    if(_mapstate == MapState::WaitingTileClick){
        if(clickedtile->GetOwner() != _players[_currentplayer]) return;
        _mapstate = MapState::Disabled;
        _highlighted = clickedtile;
        _map->Highlight(clickedtile);
        BrowseTileActions(clickedtile);
    } else if(_mapstate == MapState::WaitingTargetClick){
        if(_lastaction.name == "army move"){
            Army* a1 = clickedtile->GetArmy();
            Army* a2 = _highlighted->GetArmy();
            a2->SetActed();
            clickedtile->SetArmy(a2);
            _highlighted->SetArmy(a1);
            clickedtile->SetOwner(_highlighted->GetOwner());
            CheckWin();
        }
        if(_lastaction.name == "army attack"){
            Army* a1 = clickedtile->GetArmy();
            Army* a2 = _highlighted->GetArmy();
            a2->SetActed();
            int p1 =a1->GetPower();
            p1 *= _highlighted->GetBuilding()->GetDefenceBonus();
            int p2 =a2->GetPower();
            p2 *= 1.2 * _highlighted->GetBuilding()->GetAttackBonus();
            if(p1 > p2){
                p1 += p1 - p2;
            } else {
                p2 += p2 - p1;
            }
            a1->Damage((p2 + 1) / 2);
            a2->Damage((p1 + 1) / 2);
        }
        if(_lastaction.name == "move"){
            Unit* unit = dynamic_cast<Unit*>(_database->GetById(_lastaction.sender));
            unit->SetActed();
            Army* a1 = clickedtile->GetArmy();
            Army* a2 = _highlighted->GetArmy();
            a2->RemoveUnit(unit);
            a1->AddUnit(unit);
            clickedtile->SetOwner(_highlighted->GetOwner());
            CheckWin();
        }
        if(_lastaction.name == "attack"){
            Unit* unit = dynamic_cast<Unit*>(_database->GetById(_lastaction.sender));
            unit->SetActed();
            Army* a2 = _highlighted->GetArmy();
            Army* a1 = clickedtile->GetArmy();
            int p1 = a1->GetPower();
            p1 *= _highlighted->GetBuilding()->GetDefenceBonus();
            int p2 = unit->GetCombatPower();
            p2 *= _highlighted->GetBuilding()->GetAttackBonus();
            if(p1 > p2){
                p1 += p1 - p2;
            } else {
                p2 += p2 - p1;
            }
            a1->Damage((p2 + 1) / 2);
            unit->PureDamage((p1 + 1) / 2);
            if(unit->GetPower() <= 0){
                a2->RemoveUnit(unit);
            }
        }
        if(_lastaction.name == "shoot"){
            Unit* unit = dynamic_cast<Unit*>(_database->GetById(_lastaction.sender));
            unit->SetActed();
            Army* a1 = clickedtile->GetArmy();
            int p1 = a1->GetPower();
            p1 *= _highlighted->GetBuilding()->GetDefenceBonus();
            int p2 = unit->GetPower();
            p2 *= _highlighted->GetBuilding()->GetAttackBonus();
            if(p1 > p2){
                p1 += p1 - p2;
            } else {
                p2 += p2 - p1;
            }
            a1->Damage((p2 + 1) / 2);
        }
        Action naction(0, "purge");
        HandleAction(naction);
        return;
    } else {
        return;
    }
}

void Game::BrowseActions(int id){
    _actionfield->NewMenu();
    QVector<QString> actions = _database->GetById(id)->GetPossibleActions();
    for(int i = 0; i < actions.size(); ++i){
        AddButton(actions[i], id);
    }
}

void Game::BrowseTileActions(Tile *tile){
    _actionfield->NewMenu();
    if(tile->BuildingExists()){
        AddButton("browse", tile->GetBuilding()->id, "Действия здания");
    } else if(!_buildingcreated){
        AddButton("browse create building", tile->id, "Создать здание");
    }
    if(!tile->IsArmyEmpty()){
        if(tile->GetArmy()->CanAct()) AddButton("browse", tile->GetArmy()->id, "Действия юнитов");
    }
    AddButton("back", tile->id, "Назад");
}
