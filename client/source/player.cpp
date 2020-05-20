#include "player.h"

Player::Player(QString color) :
    _score(0),
    _money(0),
    _color(color),
    _fraction(FractionNull)
{}

QString Player::GetColor() const{
    return _color;
}

void Player::CangeMoney(int value){
    _money += value;
}

FractionType Player::getFraction()
{
    return _fraction;
}
