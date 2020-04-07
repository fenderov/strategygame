#include "buildinglist.h"

void Castle::NewBuildUnitOrder(){
    //_tile.AddUnit(CreateUnit<Archer>());
}

void Castle::Tick(){
    _unitbuildingtimer--;
    if(_unitbuildingtimer == 0){
        Unit* newunit;
        switch(_unittype){
        case ArcherType:
            newunit = CreateUnit<Archer>();
            break;
        case SwordsmanType:
            newunit = CreateUnit<Swordsman>();
            break;
        case HorsemanType:
            newunit = CreateUnit<Horseman>();
            break;
        }
        _tile.AddUnit(newunit);
    }
    _tile.ProduceMoney(_income);
}

void Barracks::Tick(){
    _unitbuildingtimer--;
    if(_unitbuildingtimer == 0){
        Unit* newunit;
        switch(_unittype){
        case ArcherType:
            newunit = CreateUnit<Archer>();
            break;
        case SwordsmanType:
            newunit = CreateUnit<Swordsman>();
            break;
        case HorsemanType:
            newunit = CreateUnit<Horseman>();
            break;
        }
        _tile.AddUnit(newunit);
    }
}

void Mine::Tick(){
    _tile.ProduceMoney(_income);
}

void Fort::Tick(){
    //and it still stand...
}
