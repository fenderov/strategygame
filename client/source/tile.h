#ifndef TILE_H
#define TILE_H

#include "widget.h"
#include "tilecontent/buildingfactory.h"
#include "tilecontent/units/unitlist.h"
#include "tilecontent/units/army.h"
#include "player.h"
#include "button.h"

#include <QWidget>
#include <QResizeEvent>
#include <QPixmap>
#include <QPainter>
#include <random>
#include <ctime>

class Tile : public Button, public BuildingFactory, public Object
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
    Action HandleAction(const Action& action) override;
    void Highlight() override;
    void Unhighlight() override;
    void Tick();
    void DrawDisabled();
    void DrawEnabled();
    ~Tile();
private:
    void Draw(const QPixmap& img);
    QPixmap _image;
    QPixmap _imagedisabled;
    Army* _army;
    Building* _building;
    Player* _owner;
};

#endif // TILE_H
