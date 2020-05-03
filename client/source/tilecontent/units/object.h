#ifndef OBJECT_H
#define OBJECT_H

#include <QVector>
#include <QString>

#include "action.h"

class Object
{
public:
    Object();
    Action DoAction(const Action& action);
    QVector<QString> GetPossibleActions();
    const unsigned int id;
private:
    static unsigned int _idencounter;
    QVector<QString> _possibleactions;
};

#endif // OBJECT_H
