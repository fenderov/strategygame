#include "army.h"

Army::Army(){

}

Army::~Army(){
    for(auto unit: _units){
        delete unit;
    }
}

bool Army::IsEmpty() const{
    return true;
}

unsigned int Army::GetPower() const{
    unsigned int power = 0;
    for(int i = 0; i < _units.size(); ++i){
        power += _units[i]->GetCombatPower();
    }
}
