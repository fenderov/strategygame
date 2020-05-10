#include "game.h"

Game::Game(QMap<size_t, QTcpSocket*> mapPlayers):
    players_(mapPlayers),
    status_(None) {
    foreach(QTcpSocket* sock, players_.values()) {
        connect(sock, &QTcpSocket::readyRead, this, &Game::slotReadClient);
        connect(sock, &QTcpSocket::stateChanged, this, &Game::slotPlayerStateHandler);
    }
    setUp();
    connect(this, &Game::gameStatusChanged, this, &Game::slotGameStatusHandler);
}

Game::~Game() {
    foreach(QTcpSocket* sock, players_.values()) {
        sock->close();
        delete sock;
    }
}

void Game::hasGotPack() {
    if (history_.empty())
        return;
    DUMMY& Pack = history_.back();

    /*if (Pack == DUMMY::ENDPACK) {
        status_ = GameStatus::End;
    }*/

    /*if (Pack.sender == status_) {
        status_ = static_cast<GameStatus>((status_ + 1) % players_.size());
    }*/

    emit gameStatusChanged();
}

void Game::setUp() {
    status_ = FirstPlayer;
    emit gameStatusChanged();
}

void Game::slotGameStatusHandler() {
    switch(status_) {
        case GameStatus::None:
            qDebug() << "None-state, you're do somtheng wrong";
            break;
        case GameStatus::End:
            qDebug() << "Game over";
            break;
        default: //That means - player turn
            DUMMY d; //Your turn man (need templates)
            send_(players_[static_cast<size_t>(status_)], d);

            DUMMY x; //Waiting for player x (also need template)
            QMap<size_t, QTcpSocket*> temp(players_);
            temp.erase(temp.find(status_));
            multySend_(temp.values(), x);
            break;
    }
}

void Game::slotPlayerStateHandler() {
    QTcpSocket* sock = static_cast<QTcpSocket*>(QObject::sender());
    qDebug() << "Status of player with id " + QString::number(sock->socketDescriptor()) + " is " + sock->state();
}
