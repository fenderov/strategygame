#ifndef PLAYER_H
#define PLAYER_H

#include "fraction.h"

#include <QString>

class Player
{
public:
    Player(QString id);
    void CangeMoney(int value);
    FractionType getFraction();
    QString GetColor() const;
private:
    const QString _color;
    unsigned int _score;
    unsigned int _money;
    FractionType _fraction;
};

#endif // PLAYER_H
