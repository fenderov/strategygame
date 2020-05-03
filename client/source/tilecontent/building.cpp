#include "building.h"

Building::Building(){

}

unsigned char Building::GetDefenceBonus() const{
    return _defencebonus;
}

unsigned char Building::GetAttackBonus() const{
    return _attackbonus;
}

bool Building::PureDamage(unsigned char damage){
    _health -= damage;
    if(_health <= 0) return true;
    else return false;
}

Building::~Building(){

}
