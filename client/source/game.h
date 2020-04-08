#ifndef GAME_H
#define GAME_H

#include "QWidget"
#include "client.h"

class Game: public QWidget
{
    Q_OBJECT

public:
    Game();
};

enum Fractions {
    FractionNull = 0,
    FractionA = 1,
    FractionB = 2
};

#endif // GAME_H
