#ifndef OBJECT_H
#define OBJECT_H

#include <QVector>
#include <QString>
#include <QObject>
#include <QDebug>

#include "action.h"

class Object
{
public:
    Object();
    virtual Action HandleAction(const Action& action);
    virtual void Highlight();
    virtual void Unhighlight();
    QVector<QString> GetPossibleActions();
    void SetPossibleActions(QVector<QString> actions);
    const unsigned int id;
private:
    static unsigned int _idencounter;
    QVector<QString> _possibleactions;
};

#endif // OBJECT_H
