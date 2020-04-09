#include "map.h"

Map::Map(QWidget *parent) : QWidget(parent){

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

    setMaximumHeight(width);
    setMaximumWidth(height);
    //setMaximumHeight(width);
    setMaximumHeight(5000);

    /*if(height < width){
        setMaximumHeight(width);
        setMaximumWidth(height);
        //setMaximumHeight(width);
        setMaximumHeight(5000);
    } else if(height > width){
        setMaximumWidth(height);
        setMaximumHeight(width);
        setMaximumWidth(5000);
    }*/
    //setMinimumWidth(height);
    //setMaximumHeight(width);
}
