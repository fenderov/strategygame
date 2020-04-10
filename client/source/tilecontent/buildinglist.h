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

class Castle : public Building, UnitFactory {
    Q_OBJECT
public:
    explicit Castle(QWidget *parent = nullptr);
    Unit* GetProducedUnits() override;
    unsigned char GetProducedMoney() override;
private:
    unsigned char _income;
};

class Barracks : public Building, UnitFactory {
    Q_OBJECT
public:
    explicit Barracks(QWidget *parent = nullptr);
    Unit* GetProducedUnits() override;
    unsigned char GetProducedMoney() override;
};

class Mine : public Building {
    Q_OBJECT
public:
    explicit Mine(QWidget *parent = nullptr);
    Unit* GetProducedUnits() override;
    unsigned char GetProducedMoney() override;
private:
    unsigned char _income;
};

class Fort : public Building {
    Q_OBJECT
public:
    explicit Fort(QWidget *parent = nullptr);
    Unit* GetProducedUnits() override;
    unsigned char GetProducedMoney() override;
private:
};

#endif // BUILDINGLIST_H
