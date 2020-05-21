#include "network.h"
#include "ui_network.h"

Network::Network(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Network) {
    ui->setupUi(this);
    _socket = nullptr;
    _connected = false;
    setStatus("red");
    ui->statusBar->showMessage("Ready to connect");
}

Network::~Network()
{
    delete ui;
}

void Network::on_connectbutton_clicked(){
    if (not _connected) {
        _socket = new QTcpSocket(this);
        connect(_socket, &QTcpSocket::connected, this,  &Network::connected);

        _socket->connectToHost(QHostAddress::LocalHost, ui->portline->text().toInt());
        ui->statusBar->showMessage("Wrong host or port");

        _connected = true;
    }
}

void Network::connected(){
    emit netconnected(_socket);
   /* _connected = true;
    setStatus("green");
    ui->statusBar->showMessage("Connected to " + ui->hostline->text() + ':' + ui->portline->text() + '!');
    ui->hostlabel->setText("Port: " + ui->hostline->text());
    ui->hostline->setVisible(false);
    ui->portlabel->setText("Port: " + ui->portline->text());
    ui->portline->setVisible(false);
    ui->connectbutton->setText("Start game");*/
}

void Network::setStatus(QString color){
    ui->status->setStyleSheet("background-color: " + color + ";");
}
