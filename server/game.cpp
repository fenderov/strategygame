#include "game.h"

Game::Game(QMap<size_t, QTcpSocket*> mapPlayers):
    players_(mapPlayers),
    curPlayer(players_.end()),
    status_(NONE) {

    foreach(QTcpSocket* sock, players_.values()) {
        connect(sock, &QTcpSocket::readyRead, this, &Game::slotReadClient);
        connect(sock, &QTcpSocket::stateChanged, this, &Game::slotPlayerStateHandler);
    }
    setUp();
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
    Package pack = history_.back().getData();

    if (pack.error_.isDefined()) {
        //Save error somewhere;
        qDebug() << "Client error";
        status_ = END;
        GameStatusHandler();
    }

    if (pack.gameData_.isDefined()) {
        //Do somthenig

        if (pack.senderId_ ==  curPlayer.key()) {
            GameStatusHandler();
        }
    }

    if (pack.text_.isDefined()) {
        qDebug() << "We get message: " + pack.text_.getText();
        if (pack.text_.getDest() == INT_MAX) {
            //multySend_();
        } else {
            send_(players_[pack.text_.getDest()], NetworkPackage(pack.senderId_, TextMessage(pack.text_.getDest(), pack.text_.getText())));
        }
    }

}

void Game::setUp() {
    status_ = GAMING;
    GameStatusHandler();
}

void Game::GameStatusHandler() {
    switch(status_) {
        case GameStatus::GAMING: {
            qDebug() << "Gaming mode";

            if (curPlayer == players_.end()) {
                curPlayer = players_.begin();
            } else {
                curPlayer++;
            }

            NetworkPackage a(0, TextMessage(curPlayer.key(), "Your turn")), b(0, TextMessage(0, "Waiting for"));
            send_(curPlayer.value(), a);

            QMap<size_t, QTcpSocket*> temp(players_);
            temp.erase(curPlayer);
            multySend_(temp.values(), b);
            break;
        }
        case GameStatus::NONE:
            qDebug() << "None-state, you're do somtheng wrong";
            break;
        case GameStatus::END:
            qDebug() << "Game over";
            emit signalGameOver();
            break;
    }
}

void Game::slotPlayerStateHandler() {
    QTcpSocket* sock = static_cast<QTcpSocket*>(QObject::sender());
    qDebug() << "Status of player with id " + QString::number(sock->socketDescriptor()) + " is " + sock->state();
}
