#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include "unitlist.h"

class UnitFactory
{
public:
    UnitFactory();
    Unit* UnitCreationTick(Fractions customer);
    void UnitCreationOrder(UnitType type);
private:
    unsigned char _unitbuildingtimer;
    UnitType _unittype;
};

#endif // UNITFACTORY_H
