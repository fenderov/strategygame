#ifndef ACTION_H
#define ACTION_H

#include <QDataStream>
#include <QString>
#include <QVector>

class Action
{
public:
    Action(int sender, QString name, QVector<int> params = QVector<int>());
    Action();
    Action(const Action&);
    static QString Name(QString action);
    int sender;
    QString name;
    QVector<int> params;

    friend QDataStream& operator << (QDataStream &out, Action const&);
    friend QDataStream& operator >> (QDataStream &in, Action&);
};

#endif // ACTION_H
