#ifndef LAND_H
#define LAND_H

#include <QMainWindow>
#include "actionfield.h"

struct Land{
    Land(std::string name, unsigned char defenceBonus, unsigned char attackBonus);
    const std::string name;
    const unsigned char defenceBonus;
    const unsigned char attackBonus;
};

#endif // LAND_H
