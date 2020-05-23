#include "database.h"

Database::Database(){

}

Object* Database::GetById(int id){
    return _map[id];
}

void Database::Register(Object* object){
    _map.insert(object->id, object);
}

void Database::Remove(int id){
    _map.remove(id);
}
