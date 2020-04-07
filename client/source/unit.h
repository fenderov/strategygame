#ifndef UNIT_H
#define UNIT_H

#include <QMainWindow>

class Unit
{
public:
    Unit();
    unsigned int GetCombatPower();
    void PureDamage(unsigned int damage);
private:
    int _power;
    int _health;
};

template <typename T>

T* CreateUnit();

#endif // UNIT_H
