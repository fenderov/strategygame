#include "unitfactory.h"
#include <QDebug>

UnitFactory::UnitFactory()
{

}

Unit* UnitFactory::UnitCreationTick(){
    --_unitbuildingtimer;
    if(_unitbuildingtimer == 0){
        switch(_unittype){
        case UnitType::ArcherType:
            return new Archer();
        case UnitType::SwordsmanType:
            return new Swordsman();
        case UnitType::HorsemanType:
            return new Horseman();
        case UnitType::UnitTypeNull:
            return nullptr;
        }
        _unittype = UnitType::UnitTypeNull;
    }
    return nullptr;
}

void UnitFactory::UnitCreationOrder(UnitType type){
    _unittype = type;
    switch(_unittype){
    case UnitType::ArcherType:
        _unitbuildingtimer = Archer::buildtime;
        break;
    case UnitType::SwordsmanType:
        _unitbuildingtimer = Swordsman::buildtime;
        break;
    case UnitType::HorsemanType:
        _unitbuildingtimer = Horseman::buildtime;
        break;
    case UnitType::UnitTypeNull:
        _unitbuildingtimer = 0;
        break;
    }
}
