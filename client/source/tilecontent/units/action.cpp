#include "action.h"

Action::Action(int sender, QString name, QVector<int> params):
    sender(sender), name(name), params(params) {
}

Action::Action():
    sender(0), name("error action"), params(QVector<int>()){
}

QString Action::Name(QString action){
    if(action == "browse create unit") return "Создать юнит";
    return "empty name";
}
