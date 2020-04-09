#ifndef BUILDING_H
#define BUILDING_H

#include "actionfield.h"
#include "unit.h"

#include <QWidget>

class Building : public QWidget
{
    Q_OBJECT

public:
    explicit Building(QWidget *parent = nullptr);
    virtual void BrowseActions(ActionField* actionfield) = 0;
    virtual Unit* GetProducedUnits() = 0;
    virtual unsigned char GetProducedMoney() = 0;
    unsigned char GetDefenceBonus() const;
    unsigned char GetAttackBonus() const;
    bool PureDamage(unsigned char damage);
    ~Building();

protected:
    unsigned char _health;
    unsigned char _defencebonus;
    unsigned char _attackbonus;
};

#endif // BUILDING_H
