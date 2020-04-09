#ifndef ARMY_H
#define ARMY_H

#include <QVector>
#include <QObject>

#include "actionfield.h"
#include "unitlist.h"

class Army : public QObject
{
    Q_OBJECT
public:
    Army();
    void AddUnit(Unit* unit);
    void BrowseActions(ActionField* actionfield);
    bool Empty() const;
    unsigned int GetPower() const;
};

#endif // ARMY_H
