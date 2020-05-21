#include "unitlist.h"

const std::map<UnitType, unsigned char> Archer::bonuses = {};
const unsigned int Archer::buildtime = 3;
const unsigned int Archer::baseactionpoints = 1;
const unsigned int Archer::basepower = 6;

const std::map<UnitType, unsigned char> Horseman::bonuses = {};
const unsigned int Horseman::buildtime = 4;
const unsigned int Horseman::baseactionpoints = 2;
const unsigned int Horseman::basepower = 10;

const std::map<UnitType, unsigned char> Swordsman::bonuses = {};
const unsigned int Swordsman::buildtime = 2;
const unsigned int Swordsman::baseactionpoints = 1;
const unsigned int Swordsman::basepower = 6;


Archer::Archer():
    Unit(basepower, baseactionpoints) {
    _image  = QPixmap("images/archer.png");
}

Horseman::Horseman():
    Unit(basepower, baseactionpoints) {
    _image  = QPixmap("images/horseman.png");
}

Swordsman::Swordsman():
    Unit(basepower, baseactionpoints) {
    _image  = QPixmap("images/swordsman.png");
}
