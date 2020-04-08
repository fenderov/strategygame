#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include "unitlist.h"
#include "player.h"

class UnitFactory
{
public:
    UnitFactory();
    Unit* UnitCreationTick(FractionType customer);
    void UnitCreationOrder(UnitType type);
private:
    unsigned char _unitbuildingtimer;
    UnitType _unittype;
};

#endif // UNITFACTORY_H
