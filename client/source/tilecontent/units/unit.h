#ifndef UNIT_H
#define UNIT_H

class Unit
{
public:
    Unit(unsigned char power, unsigned char actionpoints);
    unsigned int GetCombatPower() const;
    void PureDamage(unsigned int damage);
    void Health();
    static const unsigned int buildtime;
protected:
    unsigned char _power;
    unsigned char _actionPoints;
};

#endif // UNIT_H
