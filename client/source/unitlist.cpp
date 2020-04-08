#include "unitlist.h"

const std::map<UnitType, unsigned char> Archer::bonuses = {};
const unsigned int Archer::buildtime = 0;

const std::map<UnitType, unsigned char> Horseman::bonuses = {};
const unsigned int Horseman::buildtime = 0;

const std::map<UnitType, unsigned char> Swordsman::bonuses = {};
const unsigned int Swordsman::buildtime = 0;

Archer::Archer(FractionType customer):
    Unit(customer, 0, 0) {};

Horseman::Horseman(FractionType customer):
    Unit(customer, 0, 0) {};

Swordsman::Swordsman(FractionType customer):
    Unit(customer, 0, 0) {};
