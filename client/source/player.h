#ifndef PLAYER_H
#define PLAYER_H

#include "fraction.h"

class Player
{
public:
    Player();
    void CangeMoney(int value);
    FractionType getFraction();
private:
    unsigned int _score;
    unsigned int _money;
    FractionType _fraction;
};

#endif // PLAYER_H
