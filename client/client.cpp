#include "client.h"
#include "./ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    setFixedSize(size());
    _game = nullptr;
    connect(ui->local, &QAction::triggered, this, &Client::StartLocalGame);
    connect(ui->network, &QAction::triggered, this, &Client::ConnectNetworkGame);
}

Client::~Client()
{
    delete ui;
}

void Client::StartLocalGame(){
    _game = new Game(this);
    centralWidget()->layout()->addWidget(_game);
}

void Client::ConnectNetworkGame(){
    Network* net = new Network;
    net->show();
    connect(net, &Network::netconnected, this, &Client::StartNetworkGame);
}

void Client::StartNetworkGame(QTcpSocket* socket){
    Network* net = qobject_cast<Network*>(sender());
    net->close();
    _game = new Game(this);
    centralWidget()->layout()->addWidget(_game);
}
