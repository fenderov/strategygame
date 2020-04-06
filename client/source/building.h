#ifndef BUILDING_H
#define BUILDING_H

#include "tile.h"

class Building
{
public:
    Building(Tile& tile);
    void GetMethods(); //??? const
    virtual void NewBuildUnitOrder() = 0;
    virtual void Destroy() = 0;
    virtual void Tick() = 0;
    unsigned char GetDefenceBonus() const;
    bool Damage(unsigned char damage); //maybe void
    ~Building();
protected:
    Tile& _tile;
    unsigned char _health;
    unsigned char _defencebonus;
};

#endif // BUILDING_H
