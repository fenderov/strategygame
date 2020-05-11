#ifndef UNIT_H
#define UNIT_H

#include <QPixmap>

#include "object.h"

class Unit : public Object
{
public:
    Unit(unsigned char power, unsigned char actionpoints);
    unsigned int GetCombatPower() const;
    void PureDamage(unsigned int damage);
    void Health();
    QPixmap GetImage();
protected:
    QPixmap _image;
    unsigned char _power;
    unsigned char _actionPoints;
};

#endif // UNIT_H
