#include "buildinglist.h"

Castle::Castle(QWidget *parent) : Building(parent), _income(5){

}

Barracks::Barracks(QWidget *parent) : Building(parent){

}

Mine::Mine(QWidget *parent) : Building(parent), _income(2){

}

Fort::Fort(QWidget *parent) : Building(parent){

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
