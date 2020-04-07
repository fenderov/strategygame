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
};

class Barracks : Building {
public:
    void Tick() override;
    void NewBuildUnitOrder() override;
private:
    unsigned char _unitbuildingtimer;
};

class Mine : Building {
public:
    void Tick() override;
private:
};

class Fort : Building {
public:
    void Tick() override;
private:
};

#endif // BUILDINGLIST_H
