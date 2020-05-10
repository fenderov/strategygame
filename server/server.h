#ifndef NETWORK_H
#define NETWORK_H

#include <QMainWindow>

#include <QTcpServer>
#include <QTcpSocket>

#include "game.h"

namespace Ui {
class Server;
}

class Server : public BaseNetwork {
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private slots:
    void on_hostbutton_clicked();
    void slotNewConnection();
    void slotUpdateListUsers();

private:
    Ui::Server *ui;

    QTcpServer* server_;
    bool isListening_;

    QVector<QTcpSocket*> queue_;

    void closeAllConnections_();
    void createGame_();

    void hasGotPack() override;

    static const size_t RequairedPlayersForGame = 2;

    size_t getId_;

    QVector <Game*> games_;

    ///_____________Visual_____________///
    void setStatus_(QString color);

};

#endif // NETWORK_H
