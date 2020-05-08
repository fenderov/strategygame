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

    //Временно размер окон фиксирован.
    _map->setFixedSize(600,600);
    _actionfield->setFixedSize(300, 600);

    _layout->addWidget(_map);
    _layout->addWidget(_actionfield);
    setLayout(_layout);
    setStyleSheet("background-color: black;");

    _mapstate = MapState::WaitingTileClick;
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
    Action* action = new Action(sender, actionname, params);
    button->SetAction(action);
    button->setText(buttonname);
    connect(button, &Button::clicked, this, &Game::ActionButtonPressed);
    _actionfield->AddButton(button);
}

void Game::HandleAction(Action* action){
    if(action->name == "back"){
        if(action->sender != 0){
            _database->GetById(action->sender)->Unhighlight();
        }
        _actionfield->Pop();
        if(_mapstate = MapState::WaitingTargetClick) _mapstate = MapState::Disabled;
        if(_actionfield->IsEmpty()) _mapstate = MapState::WaitingTileClick;
    }
    if(action->name == "browse"){
        int id = action->sender;
        Object* object = _database->GetById(id);
        QVector<QString> actions = object->GetPossibleActions();

        _actionfield->NewMenu();

        for(int i = 0; i < actions.size(); ++i){
            AddButton(actions[i], id);
        }

        AddButton("back", 0, "Назад");
    }
    if(action->name == "create building"){
        _actionfield->NewMenu();
        AddButton("back", 0, "Назад");
    }
}

void Game::ActionButtonPressed(){
    Button* clickedButton = qobject_cast<Button*>(sender());
    Action* action = clickedButton->GetAction();
    HandleAction(action);
}

void Game::TilePressed(){
    Tile* clickedtile = qobject_cast<Tile*>(sender());
    if(_mapstate == MapState::WaitingTileClick){
        _mapstate = MapState::Disabled;
        clickedtile->Highlight();
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
        AddButton("create building", tile->id, "Создать здание");
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
