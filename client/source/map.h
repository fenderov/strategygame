#ifndef MAP_H
#define MAP_H

#include "tile.h"
#include <QWidget>
#include <QMainWindow>

class Map : QWidget
{
    Q_OBJECT
public:
    Map();
    void Combat(Tile* attacking, Tile* defending);

};

#endif // MAP_H
