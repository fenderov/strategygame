#include "map.h"

Map::Map(QWidget *parent) : QWidget(parent){

}

void Map::Combat(Tile *attacking, Tile *defending){
    int attackpower = attacking->GetAttackPower();
    int defencepower = defending->GetDefencePower();
    //...
}

void Map::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
