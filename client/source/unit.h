#ifndef UNIT_H
#define UNIT_H

#include <QMainWindow>
#include "player.h"

class Unit
{
public:
    Unit(FractionType customer, unsigned char power, unsigned char actionPoint);
    unsigned int GetCombatPower() const;
    void PureDamage(unsigned int damage);
    void Health();
    const FractionType owner;
protected:
    unsigned char _power;
    unsigned char _actionPoints;
};

#endif // UNIT_H
