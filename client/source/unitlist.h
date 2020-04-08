#ifndef UNITLIST_H
#define UNITLIST_H

#include "unit.h"
#include "player.h"
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
    Archer(FractionType customer);
    static const std::map<UnitType, unsigned char> bonuses;
    static const unsigned int buildtime;
};

class Swordsman : public Unit{
public:
    Swordsman(FractionType customer);
    static const std::map<UnitType, unsigned char> bonuses;
    static const unsigned int buildtime;
};

class Horseman : public Unit{
public:
    Horseman(FractionType customer);
    static const std::map<UnitType, unsigned char> bonuses;
    static const unsigned int buildtime;
};
#endif // UNITLIST_H
