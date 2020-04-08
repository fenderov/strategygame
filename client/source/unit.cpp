#include "unit.h"

Unit::Unit(FractionType customer, unsigned char power, unsigned char actionPoint) :
    owner(customer),
    _power(power),
    _actionPoints(actionPoint) {}

void Unit::PureDamage(unsigned int damage){
    _power-=damage;
}

unsigned int Unit::GetCombatPower() const{
    return _power;
}
