#include "tile.h"

#include <iostream>

Tile::Tile(QWidget *parent) : Button(parent){
    _building = nullptr;
    _army = nullptr;
    setStyleSheet("background-color: white;");
    _image = QPixmap("images/sample.png");
}

Tile::~Tile(){
    if(_army != nullptr) delete _army;
    if(_building != nullptr) delete _building;
}

bool Tile::IsArmyEmpty() const{
    return _army->IsEmpty();
}

bool Tile::BuildingExists() const{
    if(_building!=nullptr) return true;
    else return false;
}

Army* Tile::GetArmy() const{
    return _army;
}

Building* Tile::GetBuilding() const{
    return _building;
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

Player* Tile::GetOwner() const{
    return _owner;
}
void Tile::SetOwner(Player* newOwner){
    _owner = newOwner;
}

void Tile::SetBuilding(BuildingType type){
    _building = CreateBuilding(type);
}

Action* Tile::HandleAction(Action *action){
    return action;
}

void Tile::Highlight(){
    setStyleSheet("background-color: grey");
}

void Tile::Unhighlight(){
    setStyleSheet("background-color: white");
}

void Tile::Refresh(){
    std::cerr<<_image.width()<<" "<<_image.height()<<"\n";
    QIcon icon(_image);
    setIcon(icon);
    setIconSize(_image.rect().size());
}
