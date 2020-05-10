#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>

#include "basenetwork.h"

enum GameStatus {
    NONE = 0,
    GAMING = 1,
    END = INT_MAX
};

class Game : public BaseNetwork {
    Q_OBJECT
public:
    Game(QMap<size_t, QTcpSocket*>);
    ~Game();

signals:
    void signalGameOver();

private slots:
    void slotPlayerStateHandler();

private:
    void GameStatusHandler();

    QMap<size_t, QTcpSocket*> players_;
    QMap<size_t, QTcpSocket*>::iterator curPlayer;

    GameStatus status_ = NONE;

    void hasGotPack() override;
    void setUp();
};

#endif // GAME_H
