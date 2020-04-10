#include "player.h"

Player::Player() :
    _score(0),
    _money(0),
    _fraction(FractionNull)
{}

void Player::CangeMoney(int value){
    _money += value;
}

FractionType Player::getFraction()
{
    return _fraction;
}
