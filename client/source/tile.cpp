#include "tile.h"

Tile::Tile(QWidget *parent) : QWidget(parent){

}

void Tile::BrowseActions(ActionField *actionfield){
    actionfield->NewMenu();
    ActionButton *current;
    if(!_army->Empty()){
        current = actionfield->AddAction("Действия армии");
        connect(current, SIGNAL(ActionButton::clicked()), _army, SLOT(Army::BrowseActions()));
    }
    if(_building != nullptr){
        current = actionfield->AddAction("Действия здания");
        connect(current, SIGNAL(ActionButton::clicked()), _building, SLOT(Building::BrowseActions()));
    }else{
        current = actionfield->AddAction("Построить здание");
        connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(CreateBuilding(BuildingType::CastleType)));
    }
}

void Tile::BrowseCreateBuildingActions(ActionField *actionfield){
    actionfield->NewMenu();
    ActionButton *current;

    //1. Добавить провеку на деньги.
    //2. Замок игроку создать нельзя.

    //current = actionfield->AddAction("Создать замок");
    //connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuilding(actionfield, BuildingType::CastleType)));
    current = actionfield->AddAction("Создать казармы");
    connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuilding(actionfield, BuildingType::BarracksType)));
    current = actionfield->AddAction("Создать шахту");
    connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuilding(actionfield, BuildingType::MineType)));
    current = actionfield->AddAction("Создать форт");
    connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseCreateBuilding(actionfield, BuildingType::FortType)));
}

void Tile::BrowseCreateBuilding(ActionField* actionfield, BuildingType type){
    actionfield->Purge();
    CreateBuilding(type);
}

void Tile::ProduceMoney(unsigned char income){
   _owner->CangeMoney(income);
}

unsigned int Tile::GetAttackPower() const{
    int power = _army->GetPower() * _building->GetAttackBonus();
    return power;
}

unsigned int Tile::GetDefencePower() const{
    int power = _army->GetPower() * _building->GetDefenceBonus();
    return power;
}

Player* Tile::getOwner() const{
    return _owner;
}
void Tile::setOwner(Player* newOwner){
    _owner = newOwner;
}

//onclick - сравнение по овнеру
