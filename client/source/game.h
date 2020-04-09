#ifndef GAME_H
#define GAME_H

#include "QWidget"
#include "QStyleOption"
#include "QPainter"
#include "map.h"
#include "actionfield.h"

class Game: public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);
};

#endif // GAME_H
