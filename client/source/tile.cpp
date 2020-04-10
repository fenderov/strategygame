#include "tile.h"

Tile::Tile(QWidget *parent) : QWidget(parent){

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

//onclick - сравнение по овнеру
