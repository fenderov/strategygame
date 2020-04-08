#include "building.h"

Building::Building(){

}

unsigned char Building::GetDefenceBonus() const{
    return _defencebonus;
}

bool Building::PureDamage(unsigned char damage){
    _health -= damage;
    if(_health <= 0) return true;
    else return false;
}
