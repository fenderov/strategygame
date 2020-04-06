#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include "building.h"
#include "unitlist.h"

class Castle : private Building {
public:
    void NewBuildUnitOrder() override;
private:
    unsigned char _unitbuildingtimer;
};

class Barracks : Building {

};

class Mine : Building {

};

class Fort : Building {

};

#endif // BUILDINGLIST_H
