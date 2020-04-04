#ifndef GAME_H
#define GAME_H

#include <string>
#include "field.h"

class Game {
private:
    Field& field;
public:
    std::string MakeTurn();
    std::string GetTurn(std::string value);
};

std::string Game::MakeTurn();
std::string GetTurn(std::string value);

#endif