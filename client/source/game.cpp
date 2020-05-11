#include "game.h"

#include <QDebug>

Game::Game(QWidget *parent) : Widget(parent)
{
    QHBoxLayout* _layout = new QHBoxLayout();

    _database = new Database();

    _map = new Map(this);
    for(int i = 0; i < _map->GetSize().height(); ++i){
        for(int j = 0; j < _map->GetSize().width(); ++j){
            _database->Register(_map->GetTile(i, j));
            connect(_map->GetTile(i, j), &Tile::clicked, this, &Game::TilePressed);
        }
    }

    _actionfield = new ActionField(this);
    AddButton("next turn", 0, "Следующий ход");

    _layout->addWidget(_map);
    _layout->addWidget(_actionfield);
    setLayout(_layout);
    setStyleSheet("background-color: black;");
    _map->setMaximumWidth(_map->height());

    _mapstate = MapState::WaitingTileClick;
    _highlighted = nullptr;
}

Game::~Game(){
    if(_map != nullptr)
        delete _map;
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

void Game::HandleAction(const Action& action){
    if(action.name == "next turn"){
        _map->TileTick();
    }
    else if(action.name == "purge"){
        _actionfield->Purge();
        _mapstate = MapState::WaitingTileClick;
        if(_highlighted) _map->UnhighlightAll();
        _highlighted = nullptr;
    }
    else if(action.name == "back"){
        //TODO: Более кореектная проверка
        if(action.sender != 0){
            _map->UnhighlightAll();
        }
        _actionfield->Pop();
        if(_mapstate = MapState::WaitingTargetClick) _mapstate = MapState::Disabled;
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
        AddButton("create building", action.sender, "Создать шахту", QVector<int>(1, 3));
        AddButton("back", 0, "Назад");
    }
    else if(action.name == "create building"){
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
    else HandleAction(_database->GetById(action.sender)->HandleAction(action));
}

void Game::ActionButtonPressed(){
    Button* clickedButton = qobject_cast<Button*>(sender());
    Action action = clickedButton->GetAction();
    HandleAction(action);
}

void Game::TilePressed(){
    Tile* clickedtile = qobject_cast<Tile*>(sender());
    if(_mapstate == MapState::WaitingTileClick){
        _mapstate = MapState::Disabled;
        _highlighted = clickedtile;
        _map->Highlight(clickedtile);
        BrowseTileActions(clickedtile);
    } else if(_mapstate == MapState::WaitingTargetClick){
        //
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
    } else{
        AddButton("browse create building", tile->id, "Создать здание");
    }
    if(!tile->IsArmyEmpty()){
        AddButton("browse", tile->GetArmy()->id, "Действия юнитов");
    }
    AddButton("back", tile->id, "Назад");
}

























//Эта часть кода временно заморожена

/*void Game::BrowseActions(){
    _actionfield->NewMenu();
    ActionButton *current;
    current = _actionfield->AddAction("Закончить ход");
    connect(current, &ActionButton::clicked, this, &Game::EndTurn);
}

void Game::BrowseTileActions(){
    _actionfield->NewMenu();
    ActionButton *current;
    if(sender()->IsArmyEmpty()){
        current = _actionfield->AddAction("Действия армии");
        connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseActions(sender->GetArmy())));
    }
    if(sender->BuildingExists()){
        current = _actionfield->AddAction("Действия здания");
        connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseActions(sender->GetBuilding())));
    }else{
        current = _actionfield->AddAction("Построить здание");
        connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuildingActions(sender)));
    }
}

void Game::BrowseActions(Tile* sender){
    _actionfield->NewMenu();
    ActionButton *current;
    if(!sender->IsArmyEmpty()){
        current = _actionfield->AddAction("Действия армии");
        connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseActions(sender->GetArmy())));
    }
    if(sender->BuildingExists()){
        current = _actionfield->AddAction("Действия здания");
        connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseActions(sender->GetBuilding())));
    }else{
        current = _actionfield->AddAction("Построить здание");
        connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuildingActions(sender)));
    }
}

void Game::BrowseCreateBuildingActions(Tile *sender){
    _actionfield->NewMenu();
    ActionButton *current;

    //1. Добавить провеку на деньги.
    //2. Замок игроку создать нельзя.

    current = _actionfield->AddAction("Создать казармы");
    connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuilding(sender, BuildingType::BarracksType)));
    current = _actionfield->AddAction("Создать шахту");
    connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuilding(sender, BuildingType::MineType)));
    current = _actionfield->AddAction("Создать форт");
    connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuilding(sender, BuildingType::FortType)));
}

void Game::BrowseCreateBuilding(Tile *sender, BuildingType type){
    _actionfield->Purge();
    sender->CreateBuilding(type);
}*/
