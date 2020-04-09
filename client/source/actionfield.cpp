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

ActionButton* ActionField::AddAction(QString name){
    ActionButton* action = new ActionButton;
    action->setText(name);
    _actionmenus.back()->addWidget(action);
    return action;
}

void ActionField::NewMenu(){
    _actionmenus.push_back(new QGridLayout);
    //Кнопка "Назад".
}

void ActionField::Purge(){
    _actionmenus.clear();
}
