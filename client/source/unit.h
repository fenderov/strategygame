#ifndef UNIT_H
#define UNIT_H


class Unit
{
public:
    Unit();
};

template <typename T>
T* GetUnit() {
    return new T;
}

#endif // UNIT_H
