#include "map.h"

Map::Map(QWidget *parent) : Widget(parent){
    QGridLayout* _layout = new QGridLayout(this);
    _layout->setSpacing(0);
    _size.setHeight(10);
    _size.setWidth(10);
    qsrand(time(NULL));
    for(int i = 0; i < _size.height(); ++i){
        QVector<Tile*> temp;
        for(int j = 0; j < _size.width(); ++j){
            Tile* tile = new Tile(this);
            temp.push_back(tile);
            _layout->addWidget(tile, i, j);
            tile->setFixedSize(70, 70);
            tile->DrawEnabled();
            tile->show();
            tile->SetX(i);
            tile->SetY(j);
        }
        _tiles.push_back(temp);
    }
    setLayout(_layout);
    setStyleSheet("background-color: grey;");
    repaint();
}

void Map::Highlight(Tile *tile){
    for(auto vec: _tiles)
        for(auto curtile: vec)
            if(tile != curtile)
                curtile->DrawDisabled();
            else
                curtile->DrawEnabled();
}

void Map::UnhighlightAll(){
    for(auto vec: _tiles)
        for(auto curtile: vec)
            curtile->DrawEnabled();
}

Map::~Map(){
    for(int i = 0; i < _size.height(); ++i)
        for(int j = 0; j < _size.width(); ++j)
            delete _tiles[i][j];
}

void Map::TileTick(){
    for(auto vec: _tiles){
        for(auto tile: vec){
            tile->Tick();
        }
    }
}

Tile* Map::GetTile(int x, int y){
    if(x >= 0 && x < _size.height() && y >= 0 && y < _size.width())
        return _tiles[x][y];
    return nullptr;
}

QSize Map::GetSize() const{
    return _size;
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
    setMaximumWidth(height);
}
