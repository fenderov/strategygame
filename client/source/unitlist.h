#ifndef UNITLIST_H
#define UNITLIST_H

#include "unit.h"
#include "player.h"
#include "actionfield.h"

#include <QMainWindow>
#include <map>

enum UnitType {
    UnitTypeNull = 0,
    ArcherType = 1,
    HorsemanType = 2,
    SwordsmanType = 3
};

class Archer : public Unit{
public:
    Archer();
    static const std::map<UnitType, unsigned char> bonuses;
    static const unsigned int buildtime;
    static const unsigned int baseactionpoints;
    static const unsigned int basepower;
};

class Swordsman : public Unit{
public:
    Swordsman();
    static const std::map<UnitType, unsigned char> bonuses;
    static const unsigned int buildtime;
    static const unsigned int baseactionpoints;
    static const unsigned int basepower;
};

class Horseman : public Unit{
public:
    Horseman();
    static const std::map<UnitType, unsigned char> bonuses;
    static const unsigned int buildtime;
    static const unsigned int baseactionpoints;
    static const unsigned int basepower;
};
#endif // UNITLIST_H
