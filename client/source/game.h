#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFontDatabase>

#include "map.h"
#include "actionfield.h"
#include "database.h"
#include "widget.h"


enum MapState{
    WaitingTileClick,
    Disabled,
    WaitingTargetClick
};

class Game: public Widget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    Map* GetMap();
private:
    Database* _database;
    Map* _map;
    ActionField* _actionfield;
    MapState _mapstate;
    Action* _handlingaction;
    Tile* _highlighted;
    QMap<int, Player*> _players;
    int _currentplayer;
    Action _lastaction;
    bool _buildingcreated;

    void AddButton(QString actionname, int sender, QString buttonname = "sample", QVector<int> params = QVector<int>());
    void HandleAction(const Action& action);
    void BrowseActions(int id);
    void BrowseTileActions(Tile* tile);
    void CheckWin();
public slots:
    void ActionButtonPressed();
    void TilePressed();
};

#endif // GAME_H
