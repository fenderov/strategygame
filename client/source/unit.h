#ifndef UNIT_H
#define UNIT_H

#include <QMainWindow>

class Unit
{
public:
    Unit();
    unsigned int GetCombatPower();
    void PureDamage(unsigned int damage);
    static const unsigned char buildtime;
protected:
    unsigned char _power;
    unsigned char _health;
};

#endif // UNIT_H
