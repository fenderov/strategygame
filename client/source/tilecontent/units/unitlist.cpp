#include "unitlist.h"

const std::map<UnitType, unsigned char> Archer::bonuses = {};
const unsigned int Archer::buildtime = 3;
const unsigned int Archer::baseactionpoints = 1;
const unsigned int Archer::basepower = 4;

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
    QVector<QString> actions;
    actions.push_back("move");
    actions.push_back("shoot");
    SetPossibleActions(actions);
}

unsigned int Archer::GetType() const{
    return 0;
}

Horseman::Horseman():
    Unit(basepower, baseactionpoints) {
    _image  = QPixmap("images/horseman.png");
    QVector<QString> actions;
    actions.push_back("move");
    actions.push_back("attack");
    SetPossibleActions(actions);
}

unsigned int Horseman::GetType() const{
    return 1;
}

Swordsman::Swordsman():
    Unit(basepower, baseactionpoints) {
    _image  = QPixmap("images/swordsman.png");
    QVector<QString> actions;
    actions.push_back("move");
    actions.push_back("attack");
    SetPossibleActions(actions);
}

unsigned int Swordsman::GetType() const{
    return 2;
}
