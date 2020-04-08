#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>

class Player
{
public:
    Player();
    void CangeMoney(char value);
private:
    unsigned int _money;
};

#endif // PLAYER_H
