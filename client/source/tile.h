#ifndef TILE_H
#define TILE_H

#include <vector>
#include "building.h"
#include "unitlist.h"

class Tile
{
private:
    std::vector<Unit*> units;
public:
    Tile();
};

#endif // TILE_H
