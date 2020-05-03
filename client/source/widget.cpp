#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    show();
}

void Widget::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

