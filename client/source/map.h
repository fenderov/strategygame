#ifndef MAP_H
#define MAP_H

#include "tile.h"
//#include "actionfield.h"

#include <QWidget>
#include <QResizeEvent>
#include <QStyleOption>
#include <QPainter>

class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);
    void Combat(Tile* attacking, Tile* defending);
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *) override;

};

#endif // MAP_H
