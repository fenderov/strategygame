#include "object.h"

unsigned int Object::_idencounter = 1;

Object::Object() : id(_idencounter)
{
    _idencounter++;
}


QVector<QString> Object::GetPossibleActions(){
    return _possibleactions;
}

void Object::Highlight(){

}

void Object::Unhighlight(){

}

Action* Object::HandleAction(Action* action){
    return action;
}
