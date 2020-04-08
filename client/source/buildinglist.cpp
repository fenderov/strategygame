#include "buildinglist.h"

Castle::Castle(Tile& tile) : Building(tile){

}

void Castle::NewBuildUnitOrder(){
    //_tile.AddUnit(CreateUnit<Archer>());
}

void Castle::Tick(){
    Unit* newunit = UnitCreationTick();
    if(newunit != nullptr) _tile.AddUnit(newunit);
    _tile.ProduceMoney(_income);
}

void Barracks::Tick(){
    Unit* newunit = UnitCreationTick();
    if(newunit != nullptr) _tile.AddUnit(newunit);
}

void Mine::Tick(){
    _tile.ProduceMoney(_income);
}

void Fort::Tick(){
    //and it still stand...
}