#include "building.h"

Building::Building(){

}

float Building::GetDefenceBonus() const{
    return _defencebonus;
}

float Building::GetAttackBonus() const{
    return _attackbonus;
}

bool Building::PureDamage(unsigned char damage){
    _health -= damage;
    if(_health <= 0) return true;
    else return false;
}

QPixmap Building::GetImage(){
    return _image;
}

Building::~Building(){

}
