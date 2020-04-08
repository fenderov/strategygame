#include "actionfield.h"

ActionField::ActionField(QWidget *parent) : QWidget(parent)
{

}

void ActionField::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
