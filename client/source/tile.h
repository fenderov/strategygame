#ifndef TILE_H
#define TILE_H

#include <vector>
#include "building.h"
#include "unitlist.h"
#include "player.h"
#include <QMainWindow>

class Tile
{
public:
    Tile();
    void AddUnit(Unit*);
    void ProduceMoney(unsigned char income);
    unsigned int GetBasePower();
    unsigned int GetAttackPower();
    unsigned int GetDefencePower();
private:
    std::vector<Unit*> _units;
    Building* _building;
    Player* _owner;
};

#endif // TILE_H
