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
    void RemoveUnit(Unit* unit);
    bool IsEmpty() const;
    unsigned int GetPower() const;
    void Unite();
    void Divide();
    void Damage(int power);
    Action HandleAction(const Action &action);
    QPixmap GetImage();
    const QVector<Unit*>& GetUnits() const;
    bool CanAct() const;
    void Refresh();
    void SetActed();
    ~Army();
private:
    bool _united;
    bool _canact;
    QVector<Unit*> _units;
};

#endif // ARMY_H
