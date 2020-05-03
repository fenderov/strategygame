#ifndef MAP_H
#define MAP_H

#include "tile.h"
#include "widget.h"
//#include "actionfield.h"

#include <QWidget>
#include <QResizeEvent>
#include <QVector>
#include <QSize>
#include <QGridLayout>

class Map : public Widget
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    Tile* GetTile(int x, int y);
    void Combat(Tile* attacking, Tile* defending);
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
private:
    QVector<QVector<Tile*>> _tiles;
    QSize _size;
};

#endif // MAP_H
