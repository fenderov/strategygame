#include "map.h"

Map::Map(QWidget *parent) : QWidget(parent){
    _size.setHeight(10);
    _size.setWidth(10);
    for(int i = 0; i < _size.height(); ++i){
        QVector<Tile*> temp;
        for(int j = 0; j < _size.width(); ++j)
            temp.push_back(new Tile(this));
        _tiles.push_back(temp);
    }
}

Map::~Map(){
    for(int i = 0; i < _size.height(); ++i)
        for(int j = 0; j < _size.width(); ++j)
            delete _tiles[i][j];
}

Tile* Map::GetTile(int x, int y){
    return _tiles[x][y];
}

void Map::Combat(Tile *attacking, Tile *defending){
    int attackpower = attacking->GetAttackPower();
    int defencepower = defending->GetDefencePower();
    //...
}

void Map::paintEvent(QPaintEvent*){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Map::resizeEvent(QResizeEvent *event){
    int height = event->size().height();
    int oldheight = event->oldSize().height();
    int width = event->size().width();
    int oldwidth = event->oldSize().width();

    //Здесь будет настройка дизайна карты.
    //По задумке она должна быть всегда квадратной.

    //setMaximumHeight(width);
    //setMaximumWidth(height);
    //setMaximumHeight(5000);
}
