#include "map.h"

Map::Map(QWidget *parent) : Widget(parent){
    QGridLayout* _layout = new QGridLayout(this);
    _size.setHeight(10);
    _size.setWidth(10);
    for(int i = 0; i < _size.height(); ++i){
        QVector<Tile*> temp;
        for(int j = 0; j < _size.width(); ++j){
            Tile* tile = new Tile(this);
            temp.push_back(tile);
            _layout->addWidget(tile, i, j);
            tile->show();
        }
        _tiles.push_back(temp);
    }
    setLayout(_layout);
    setStyleSheet("background-color: grey;");
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
