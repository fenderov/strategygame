#include "action.h"

Action::Action(int sender, QString name, QVector<int> params):
    sender(sender), name(name), params(params) {
}

Action::Action():
    sender(0), name("error action"), params(QVector<int>()){
}

QString Action::Name(QString action){
    if(action == "browse create unit") return "Создать юнит";
    if(action == "unite") return "Объединить юниты";
    if(action == "divide") return "Разделить армию";
    if(action == "browse units") return "Действия отдельных юнитов";
    if(action == "army move") return "Двигаться армией";
    if(action == "army attack") return "Атаковать армией";
    if(action == "move") return "Двигаться";
    if(action == "attack") return "Атаковать";
    if(action == "shoot") return "Выстрелить";
    return "empty name";
}
