#ifndef ACTION_H
#define ACTION_H

#include <QString>
#include <QVector>

class Action
{
public:
    Action(int sender, QString name, QVector<int> params = QVector<int>());
    Action();
public:
    const int sender;
    const QString name;
    const QVector<int> params;
};

#endif // ACTION_H
