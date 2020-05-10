#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>

#include "basenetwork.h"

enum GameStatus {
    None = 0,
    FirstPlayer = 1,
    SecondPlayer = 2,
    End = INT_MAX
};

class Game : public BaseNetwork {
    Q_OBJECT
public:
    Game(QMap<size_t, QTcpSocket*>);
    ~Game();

signals:
    void gameStatusChanged();

private slots:
    void slotGameStatusHandler();
    void slotPlayerStateHandler();

private:
    QMap<size_t, QTcpSocket*> players_;
    GameStatus status_ = None;

    void hasGotPack() override;
    void setUp();
};

#endif // GAME_H
