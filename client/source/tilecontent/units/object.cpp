#include "object.h"

unsigned int Object::_idencounter = 1;

Object::Object() : id(_idencounter)
{
    _idencounter++;
}


QVector<QString> Object::GetPossibleActions(){
    return _possibleactions;
}

void Object::SetPossibleActions(QVector<QString> actions){
    _possibleactions = actions;
}


void Object::Highlight(){

}

void Object::Unhighlight(){

}

Action Object::HandleAction(const Action& action){
    return Action(0, "back");
}
