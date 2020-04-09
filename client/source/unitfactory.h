#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include "unitlist.h"
#include "player.h"
#include "actionfield.h"

class UnitFactory
{
public:
    UnitFactory();
    Unit* UnitCreationTick();
    void UnitCreationOrder(UnitType type);
    void BrowseBuildUnitActions(ActionField* actionfield);
private:
    unsigned char _unitbuildingtimer;
    UnitType _unittype;
};

#endif // UNITFACTORY_H
