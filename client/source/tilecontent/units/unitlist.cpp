#include "unitlist.h"

const std::map<UnitType, unsigned char> Archer::bonuses = {};
const unsigned int Archer::buildtime = 2;
const unsigned int Archer::baseactionpoints = 0;
const unsigned int Archer::basepower = 0;

const std::map<UnitType, unsigned char> Horseman::bonuses = {};
const unsigned int Horseman::buildtime = 3;
const unsigned int Horseman::baseactionpoints = 0;
const unsigned int Horseman::basepower = 0;

const std::map<UnitType, unsigned char> Swordsman::bonuses = {};
const unsigned int Swordsman::buildtime = 1;
const unsigned int Swordsman::baseactionpoints = 0;
const unsigned int Swordsman::basepower = 0;

Archer::Archer():
    Unit(basepower, baseactionpoints) {};

Horseman::Horseman():
    Unit(basepower, baseactionpoints) {};

Swordsman::Swordsman():
    Unit(basepower, baseactionpoints) {};
