#include "unit.h"

Unit::Unit(unsigned char power, unsigned char actionpoints) :
    _power(power),
    _actionpoints(actionpoints) {
    _cpower = _power/2;
    _canact = true;
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

unsigned int Unit::GetActionPoints() const{
    return _actionpoints;
}

QPixmap Unit::GetImage(){
    return _image;
}

bool Unit::CanAct() const{
    return _canact;
}

void Unit::Refresh(){
    _canact = true;
}

void Unit::SetActed(){
    _canact = false;
}
