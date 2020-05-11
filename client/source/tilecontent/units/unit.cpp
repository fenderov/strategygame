#include "unit.h"

Unit::Unit(unsigned char power, unsigned char actionpoints) :
    _power(power),
    _actionPoints(actionpoints) {}

void Unit::PureDamage(unsigned int damage){
    _power-=damage;
}

unsigned int Unit::GetCombatPower() const{
    return _power;
}

QPixmap Unit::GetImage(){
    return _image;
}
