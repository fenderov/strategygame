#include "tile.h"

Tile::Tile()
{

}

void Tile::ProduceMoney(unsigned char income){
   _owner->CangeMoney(income);
}

unsigned int Tile::GetBasePower(){
    int basepower = 0;
    for(unsigned int i = 0; i < _units.size(); ++i){
        basepower += _units[i]->GetCombatPower();
    }
    return basepower;
}

unsigned int Tile::GetAttackPower(){
    int power = GetBasePower();// * _building->GetAttackBonus() //equal to 1x defence;
    return power;
}

unsigned int Tile::GetDefencePower(){
    int power = GetBasePower() * _building->GetDefenceBonus();
    return power;
}

Player* Tile::getOwner(){
    return _owner;
}
void Tile::setOwner(Player* newOwner){
    _owner = newOwner;
}
