#ifndef OBJECT_H
#define OBJECT_H

#include <QVector>
#include <QString>

#include "action.h"

class Object
{
public:
    Object();
    virtual Action* HandleAction(Action* action);
    virtual void Highlight();
    virtual void Unhighlight();
    QVector<QString> GetPossibleActions();
    const unsigned int id;
private:
    static unsigned int _idencounter;
    QVector<QString> _possibleactions;
};

#endif // OBJECT_H
