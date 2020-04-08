#ifndef UNITLIST_H
#define UNITLIST_H

#include "unit.h"
#include <QMainWindow>

class Archer : public Unit{
public:
    Archer();
    static const unsigned char buildtime = 2;
};

class Swordsman : public Unit{
public:
    Swordsman();
    static const unsigned char buildtime = 2;
};

class Horseman : public Unit{
public:
    Horseman();
    static const unsigned char buildtime = 2;
};

enum UnitType {
    ArcherType,
    SwordsmanType,
    HorsemanType,
    _void
};

#endif // UNITLIST_H
