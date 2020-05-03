#include "game.h"

Game::Game(QWidget *parent) : Widget(parent)
{
    QHBoxLayout* _layout = new QHBoxLayout();
    _map = new Map(this);
    _map->setMinimumSize(400, 400);
    _actionfield = new ActionField(this);
    //QSizePolicy mappolicy;
    //QSizePolicy actionfieldpolicy;
    //mappolicy.setHorizontalStretch(100);
    //actionfieldpolicy.setHorizontalStretch(20);
    //_map->setSizePolicy(mappolicy);
    //_actionfield->setSizePolicy(actionfieldpolicy);
    _layout->addWidget(_map);
    _layout->addWidget(_actionfield);
    setLayout(_layout);
    setStyleSheet("background-color: black;");
}

Game::~Game(){
    if(_map != nullptr)
        delete _map;
}

Map* Game::GetMap(){
    return _map;
}

void Game::HandleAction(Action* action){
    //TODO
}

void Game::HandleActionSlot(){
    Button* clickedButton = qobject_cast<Button *>(sender());
    Action* action = clickedButton->GetAction();
    HandleAction(action);
}

void Game::BrowseActions(int id){
    _actionfield->NewMenu();
    QVector<QString> actions = _database->GetById(id)->GetPossibleActions();
    for(auto action: actions){
        _actionfield->AddAction(new Action(id, action, nullptr));
    }
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
