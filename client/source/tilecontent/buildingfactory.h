#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "buildinglist.h"

class BuildingFactory
{
public:
    BuildingFactory();
    Building* CreateBuilding(BuildingType type);
};

#endif // BUILDINGFACTORY_H
