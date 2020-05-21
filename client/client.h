#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include "source/game.h"
#include "network.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private:
    Game* _game;
    Ui::Client *ui;

private slots:
    void StartNetworkGame(QTcpSocket* socket);
    void StartLocalGame();
    void ConnectNetworkGame();
};
#endif // CLIENT_H
