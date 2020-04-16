#include "game.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    _map = new Map(this);
}

Game::~Game(){
    if(_map != nullptr)
        delete _map;
}

Map* Game::GetMap(){
    return _map;
}

void Game::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
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
