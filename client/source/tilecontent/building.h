#ifndef BUILDING_H
#define BUILDING_H

#include "units/unit.h"

#include <QWidget>

class Building : public Object
{

public:
    explicit Building();
    virtual Unit* GetProducedUnits() = 0;
    virtual unsigned char GetProducedMoney() = 0;
    virtual float GetDefenceBonus() const = 0;
    virtual float GetAttackBonus() const = 0;
    bool PureDamage(unsigned char damage);
    ~Building();
    QPixmap GetImage();
protected:
    QPixmap _image;
    unsigned char _health;
    unsigned char _defencebonus;
    unsigned char _attackbonus;
};

#endif // BUILDING_H
