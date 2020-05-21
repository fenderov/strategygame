#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include "building.h"
#include "units/unitfactory.h"

#include <QWidget>

enum BuildingType {
    BuildingTypeNull = 0,
    CastleType = 1,
    BarracksType = 2,
    MineType = 3,
    FortType = 4
};

class Castle : public Building, public UnitFactory {
public:
    Castle();
    Unit* GetProducedUnits() override;
    unsigned char GetProducedMoney() override;
    Action HandleAction(const Action& action) override;
private:
    const unsigned char _income;
};

class Barracks : public Building, public UnitFactory {
public:
    Barracks();
    Unit* GetProducedUnits() override;
    unsigned char GetProducedMoney() override;
    Action HandleAction(const Action& action) override;
};

class Mine : public Building {
public:
    Mine();
    Unit* GetProducedUnits() override;
    unsigned char GetProducedMoney() override;
    Action HandleAction(const Action& action) override;
private:
    const unsigned char _income;
};

class Fort : public Building {
public:
    Fort();
    Unit* GetProducedUnits() override;
    unsigned char GetProducedMoney() override;
    Action HandleAction(const Action& action) override;
private:
};

#endif // BUILDINGLIST_H
