#ifndef TILE_H
#define TILE_H

#include "widget.h"
#include "tilecontent/buildingfactory.h"
#include "tilecontent/units/unitlist.h"
#include "tilecontent/units/army.h"
#include "player.h"

#include <QWidget>
#include <QResizeEvent>

class Tile : public Widget, public BuildingFactory
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
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
private:
    Army* _army;
    Building* _building;
    Player* _owner;
};

#endif // TILE_H
