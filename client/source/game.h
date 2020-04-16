#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

#include "map.h"
//#include "actionfield.h"

class Game: public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    Map* GetMap();
    //void BrowseActions();
protected:
    void paintEvent(QPaintEvent *);
private:
    Map* _map;
    //ActionField* _actionfield;
public slots:
    /*void EndTurn();
    void BrowseTileActions();
    void BrowseTileCreateBuildingActions();
    void BrowseBuildingActions();
    void BrowseBuildingCreateUnitActions();
    void BrowseArmyUnitedActions();
    void BrowseArmyReunitedActions();
    void BrowseUnitActions();
    void BrowseUnitAttackActions();
    void BrowseUnitMoveActions();*/
};

#endif // GAME_H
