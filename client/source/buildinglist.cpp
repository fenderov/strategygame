#include "buildinglist.h"

void Castle::NewBuildUnitOrder() {
    _tile.AddUnit(GetUnit<Archer>());
}
