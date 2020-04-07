#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include "building.h"
#include "unitfactory.h"
#include <QMainWindow>

class Castle : Building, UnitFactory {
public:
    Castle(Tile& tile);
    void Tick() override;
    void NewBuildUnitOrder() override;
private:
    unsigned char _income;
};

class Barracks : Building, UnitFactory {
public:
    Barracks(Tile& tile);
    void Tick() override;
    void NewBuildUnitOrder() override;
private:
    unsigned char _unitbuildingtimer;
    UnitType _unittype;
    UnitFactory* _factory;
};

class Mine : Building {
public:
    void Tick() override;
private:
    unsigned char _income;
};

class Fort : Building {
public:
    void Tick() override;
private:
};

#endif // BUILDINGLIST_H
