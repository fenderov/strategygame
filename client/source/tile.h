#ifndef TILE_H
#define TILE_H

#include <vector>
#include "building.h"
#include "unitlist.h"
#include <QMainWindow>

class Tile
{
public:
    Tile();
    void AddUnit(Unit*);
private:
    std::vector<Unit*> _units;
};

#endif // TILE_H
