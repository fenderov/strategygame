#ifndef ARMY_H
#define ARMY_H

#include <QVector>
#include <QObject>

#include "unitlist.h"

class Army : public QObject
{
    Q_OBJECT
public:
    Army();
    void AddUnit(Unit* unit);
    bool IsEmpty() const;
    unsigned int GetPower() const;
};

#endif // ARMY_H