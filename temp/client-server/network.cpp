#include "network.h"
#include "ui_network.h"

Network::Network(QWidget *parent) :
    BaseNetwork(parent),
    ui(new Ui::Network)
{
    ui->setupUi(this);
    ui->messagelabel->setVisible(false);
    ui->messageline->setVisible(false);
    ui->sendbutton->setVisible(false);
    setStatus("red");
    mode = None;
    socket = nullptr;
    blocksize = 0;
}

Network::~Network()
{
    delete ui;
}

void Network::hasGotPack() {
    if (history_.empty())
        return;

    Package pack = history_.back().getData();
    if (pack.text_.isDefined()) {
        qDebug() << "Client has got new message : '" + pack.text_.getText() + "'";
    }
}

void Network::on_connectbutton_clicked(){

    if(socket != nullptr){
        socket->close();
        delete socket;
    }
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress(QHostAddress::LocalHost), ui->portline->text().toInt());
    connect(socket, &QTcpSocket::connected, this,  &Network::connected);
    connect(socket, &QTcpSocket::readyRead, this,  &Network::slotReadClient);
}

void Network::on_sendbutton_clicked(){
    send_(socket, NetworkPackage(0, TextMessage(INT_MAX, ui->messageline->text())));
}

void Network::connected()
{
    setStatus("green");

    mode = Client;
    setWindowTitle("Client");

    ui->messagelabel->setVisible(true);
    ui->messageline->setVisible(true);
    ui->sendbutton->setVisible(true);
    ui->connectbutton->setVisible(false);
    ui->portline->setVisible(false);

    ui->portlabel->setText(ui->portlabel->text() + " " + ui->portline->text());
    qDebug() << socket->peerName();
}

void Network::setStatus(QString color){
    ui->status->setStyleSheet("background-color: " + color + ";");
}
