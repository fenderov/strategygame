#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include "building.h"
#include "unitlist.h"
#include <QMainWindow>

enum UnitType {
    ArcherType,
    SwordsmanType,
    HorsemanType
};

class Castle : private Building {
public:
    void Tick() override;
    void NewBuildUnitOrder() override;
private:
    unsigned char _unitbuildingtimer;
    UnitType _unittype;
    unsigned char _income;
};

class Barracks : Building {
public:
    void Tick() override;
    void NewBuildUnitOrder() override;
private:
    unsigned char _unitbuildingtimer;
    UnitType _unittype;
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
