#include "army.h"

Army::Army(){

}

Army::~Army(){
    for(unsigned int i = 0; i < _units.size(); ++i){
        delete _units[i];
    }
}

bool Army::IsEmpty() const{
    return true;
}

unsigned int Army::GetPower() const{
    return 0;
}
