#include "buildinglist.h"

Castle::Castle() : _income(5){

}

Barracks::Barracks(){

}

Mine::Mine() : _income(2){

}

Fort::Fort(){

}

Unit* Castle::GetProducedUnits(){
    return UnitCreationTick();
}

unsigned char Castle::GetProducedMoney(){
    return _income;
}

Unit* Barracks::GetProducedUnits(){
    return UnitCreationTick();
}

unsigned char Barracks::GetProducedMoney(){
    return 0;
}

Unit* Mine::GetProducedUnits(){
    return nullptr;
}

unsigned char Mine::GetProducedMoney(){
    return _income;
}

Unit* Fort::GetProducedUnits(){
    return nullptr;
}

unsigned char Fort::GetProducedMoney(){
    return 0;
}
