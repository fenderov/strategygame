#include "unitfactory.h"

UnitFactory::UnitFactory()
{

}

Unit* UnitFactory::UnitCreationTick(FractionType customer){
    if(_unitbuildingtimer > 0) _unitbuildingtimer--;
    if(_unitbuildingtimer == 0){
        switch(_unittype){
        case UnitType::ArcherType:
            return new Archer(customer);
        case UnitType::SwordsmanType:
            return new Swordsman(customer);
        case UnitType::HorsemanType:
            return new Horseman(customer);
        case UnitType::UnitTypeNull:
            return nullptr;
        }
    }
    return nullptr;
}

void UnitFactory::UnitCreationOrder(UnitType type){
    _unittype = type;
    switch(_unittype){
    case UnitType::ArcherType:
        _unitbuildingtimer = Archer::buildtime;
    case UnitType::SwordsmanType:
        _unitbuildingtimer = Swordsman::buildtime;
    case UnitType::HorsemanType:
        _unitbuildingtimer = Horseman::buildtime;
    case UnitType::UnitTypeNull:
        _unitbuildingtimer = 0;
    }
}
