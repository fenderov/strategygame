#include "unit.h"

Unit::Unit()
{

}

template <typename T>

T* CreateUnit() {
    return new T;
}
