#ifndef TILE_H
#define TILE_H

#include <vector>
#include "tilecontent/buildingfactory.h"
#include "tilecontent/units/unitlist.h"
#include "tilecontent/units/army.h"
#include "player.h"

#include <QWidget>

class Tile : public QWidget, public BuildingFactory
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent = nullptr);
    void AddUnit(Unit*);
    void SetBuilding(BuildingType type);
    void ProduceMoney(unsigned char income);
    Army* GetArmy() const;
    Building* GetBuilding() const;
    bool IsArmyEmpty() const;
    bool BuildingExists() const;
    unsigned int GetAttackPower() const;
    unsigned int GetDefencePower() const;
    Player* GetOwner() const;
    void SetOwner(Player* newowner);
    ~Tile();
private:
    Army* _army;
    Building* _building;
    Player* _owner;
};

#endif // TILE_H
