#include "object.h"

unsigned int Object::_idencounter = 0;

Object::Object() : id(_idencounter)
{
    _idencounter++;
}


QVector<QString> Object::GetPossibleActions(){
    return _possibleactions;
}
