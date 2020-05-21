#include "action.h"

Action::Action(int sender, QString name, QVector<int> params):
    sender(sender), name(name), params(params) {}

Action::Action():
    sender(0), name("error action"), params(QVector<int>()){}

Action::Action(const Action& right) :
    sender(right.sender), name(right.name), params(right.params){}

QString Action::Name(QString action){
    if(action == "browse create unit") return "Создать юнит";
    if(action == "unite") return "Объединить юниты";
    if(action == "divide") return "Разделить армию";
    if(action == "browse units") return "Действия отдельных юнитов";
    if(action == "army move") return "Двигаться армией";
    if(action == "army attack") return "Атаковать армией";
    return "empty name";
}

QDataStream& operator << (QDataStream &out, Action const& act) {
    out << act.sender << act.name << act.params;
    return out;
}

QDataStream& operator >> (QDataStream &in, Action& act) {
    in >> act.sender >> act.name >> act.params;
    return in;
}
