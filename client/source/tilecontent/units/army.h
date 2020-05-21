#ifndef ARMY_H
#define ARMY_H

#include <QVector>
#include <QPainter>
#include "unitlist.h"

class Army : public Object
{
public:
    Army();
    void AddUnit(Unit* unit);
    bool IsEmpty() const;
    unsigned int GetPower() const;
    void Unite();
    void Divide();
    void Damage(int power);
    Action HandleAction(const Action &action);
    QPixmap GetImage();
    ~Army();
private:
    bool _united;
    QVector<Unit*> _units;
};

#endif // ARMY_H
