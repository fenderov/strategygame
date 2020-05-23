#ifndef UNITLIST_H
#define UNITLIST_H

#include "unit.h"

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
    unsigned int GetType() const;
};

class Swordsman : public Unit{
public:
    Swordsman();
    static const std::map<UnitType, unsigned char> bonuses;
    static const unsigned int buildtime;
    static const unsigned int baseactionpoints;
    static const unsigned int basepower;
    unsigned int GetType() const;
};

class Horseman : public Unit{
public:
    Horseman();
    static const std::map<UnitType, unsigned char> bonuses;
    static const unsigned int buildtime;
    static const unsigned int baseactionpoints;
    static const unsigned int basepower;
    unsigned int GetType() const;
};
#endif // UNITLIST_H
