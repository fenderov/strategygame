#ifndef MAP_H
#define MAP_H

#include "tile.h"
#include <QWidget>
#include "QStyleOption"
#include "QPainter"

class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);
    void Combat(Tile* attacking, Tile* defending);
protected:
    void paintEvent(QPaintEvent *);

};

#endif // MAP_H
