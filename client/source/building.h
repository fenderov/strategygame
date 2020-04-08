#ifndef BUILDING_H
#define BUILDING_H

#include "tile.h"
#include <QMainWindow>
#include <QObject>

class Building : QObject
{
    Q_OBJECT
public:
    Building(Tile& tile);
    void GetMethods(); //??? const
    virtual void NewBuildUnitOrder() = 0;
    virtual void Destroy() = 0;
    virtual void Tick() = 0;
    unsigned char GetDefenceBonus() const;
    bool PureDamage(unsigned char damage); //maybe void
    ~Building();

protected:
    Tile& _tile;
    unsigned char _health;
    unsigned char _defencebonus;
    unsigned char _attackbonus = 100;
};

#endif // BUILDING_H
