#include "unit.h"

Unit::Unit(unsigned char power, unsigned char actionpoints) :
    _power(power),
    _actionPoints(actionpoints) {
    _cpower = _power/2;
}

void Unit::PureDamage(unsigned int damage){
    _power-=damage;
}

unsigned int Unit::GetCombatPower() const{
    return std::max(_power, _cpower);
}

unsigned int Unit::GetPower() const{
    return _power;
}

QPixmap Unit::GetImage(){
    return _image;
}
