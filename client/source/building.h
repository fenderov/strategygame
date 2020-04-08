#ifndef BUILDING_H
#define BUILDING_H

#include <QObject>

class Building : QObject
{
    Q_OBJECT
public:
    Building();
    void GetMethods(); //??? const
    virtual void Destroy() = 0;
    virtual void Tick() = 0;
    unsigned char GetDefenceBonus() const;
    bool PureDamage(unsigned char damage); //maybe void
    ~Building();

protected:
    unsigned char _health;
    unsigned char _defencebonus;
    unsigned char _attackbonus = 100;
};

#endif // BUILDING_H
