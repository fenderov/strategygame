#ifndef MAP_H
#define MAP_H

#include "tile.h"
//#include "actionfield.h"

#include <QWidget>
#include <QResizeEvent>
#include <QStyleOption>
#include <QPainter>
#include <QVector>
#include <QSize>

class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    Tile* GetTile(int x, int y);
    void Combat(Tile* attacking, Tile* defending);
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *) override;
private:
    QVector<QVector<Tile*>> _tiles;
    QSize _size;
};

#endif // MAP_H
