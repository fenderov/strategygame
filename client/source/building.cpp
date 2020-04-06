#include "building.h"

Building::Building(Tile& tile): _tile(tile){

}

unsigned char Building::GetDefenceBonus() const{
    return _defencebonus;
}

bool Building::Damage(unsigned char damage){
    _health -= damage;
    if(_health <= 0) return true;
    else return false;
}
