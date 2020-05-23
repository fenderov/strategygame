#include "actionfield.h"

ActionField::ActionField(QWidget *parent) : Widget(parent)
{
    setStyleSheet("background-color: grey;");
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);
    NewMenu();
}

ActionField::~ActionField(){
    Purge();
    delete layout();
}

void ActionField::NewMenu(){
    QLayoutItem* item;
    while (!layout()->count() == 0) {
        item = layout()->takeAt(0);
        item->widget()->setParent(nullptr);
        layout()->removeItem(item);
        delete item;
    }
    Menu* menu = new Menu;
    menu->buttons = QVector<Button*>();
    _menus.push_back(menu);
}

void ActionField::AddButton(Button* button){
    _menus[_menus.size() - 1]->buttons.push_back(button);
    layout()->addWidget(button);
}

void ActionField::Pop(){
    QLayoutItem* item;
    while ((item = layout()->takeAt(0)) != 0) {
        delete item->widget();
        delete item;
    }
    delete _menus[_menus.size() - 1];
    _menus.pop_back();
    Menu* current = _menus[_menus.size() - 1];
    for(int i = 0; i < current->buttons.size(); ++i){
        layout()->addWidget(current->buttons[i]);
    }
}

void ActionField::Purge(){
    while(_menus.size() > 1) Pop();
}

bool ActionField::IsEmpty(){
    if(_menus.size() > 1) return false;
    else return true;
}
