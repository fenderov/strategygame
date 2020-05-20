#ifndef UNIT_H
#define UNIT_H

#include <QPixmap>

#include "object.h"

class Unit : public Object
{
public:
    Unit(unsigned char power, unsigned char actionpoints);
    unsigned int GetCombatPower() const;
    unsigned int GetPower() const;
    void PureDamage(unsigned int damage);
    void Health();
    QPixmap GetImage();
    unsigned int GetActionPoints() const;
protected:
    QPixmap _image;
    unsigned char _power;
    unsigned char _cpower;
    unsigned char _actionpoints;
};

#endif // UNIT_H
