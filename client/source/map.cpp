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

    //Здесь будет настройка дизайна карты.
    //По задумке она должна быть всегда квадратной.

    //setMaximumHeight(width);
    //setMaximumWidth(height);
    //setMaximumHeight(5000);
}
