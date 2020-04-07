#include "unit.h"

Unit::Unit()
{

}

void Unit::PureDamage(unsigned int damage){
    _health-=damage;
}

unsigned int Unit::GetCombatPower(){
    return _power*_health;
}

template <typename T>

T* CreateUnit() {
    return new T;
}
