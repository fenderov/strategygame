#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QHBoxLayout>

#include "map.h"
#include "actionfield.h"
#include "database.h"
#include "widget.h"

class Game: public Widget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    Map* GetMap();
    void HandleAction(Action* action);
    void BrowseActions(int id);
private:
    Database* _database;
    Map* _map;
    ActionField* _actionfield;
public slots:
    void HandleActionSlot();
};

#endif // GAME_H
