#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include "game.h"

class Player
{
public:
    Player();
    void CangeMoney(int value);
    Fractions getFraction();
private:
    unsigned int _score;
    unsigned int _money;
    Fractions _fraction;
};

#endif // PLAYER_H
