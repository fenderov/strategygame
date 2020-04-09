#ifndef TILE_H
#define TILE_H

#include <vector>
#include "buildingfactory.h"
#include "unitlist.h"
#include "player.h"
#include "actionfield.h"
#include "army.h"

#include <QWidget>

class Tile : public QWidget, BuildingFactory
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent = nullptr);
    void AddUnit(Unit*);
    void ProduceMoney(unsigned char income);
    unsigned int GetAttackPower() const;
    unsigned int GetDefencePower() const;
    Player* getOwner() const;
    void setOwner(Player* newowner);
public slots:
    void BrowseActions(ActionField* actionfield);
    void BrowseCreateBuildingActions(ActionField* actionfield);
    void BrowseCreateBuilding(ActionField* actionfield, BuildingType type);
private:
    Army* _army;
    Building* _building;
    Player* _owner;
};

#endif // TILE_H
