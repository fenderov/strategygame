#ifndef DATABASE_H
#define DATABASE_H

#include "tilecontent/units/object.h"

#include <QMap>

class Database
{
public:
    Database();
    Object* GetById(int id);
    void Register(Object* object);
    void Remove(int id);
private:
    QMap<int, Object*> map;
};

#endif // DATABASE_H
