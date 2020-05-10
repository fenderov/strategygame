#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    BaseNetwork(parent),
    ui(new Ui::Server),
    server_(new QTcpServer(static_cast<QMainWindow*>(this))),
    isListening_(false),
    getId_(1) {
    ui->setupUi(this);
    setStatus_("red");
}

Server::~Server() {
    closeAllConnections_();
    delete server_;
    delete ui;
}

void Server::on_hostbutton_clicked()
{
    if (!server_->listen(QHostAddress::Any, ui->portline->text().toInt()) && !isListening_) {
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(server_->errorString());
    } else {
        isListening_ = true;
        qDebug() << "The server has been set up";
    }
    connect(server_, &QTcpServer::newConnection, this, &Server::slotNewConnection);

    setStatus_("yellow");
}

void Server::slotNewConnection(){
    if(isListening_){
        qDebug() << "New connection";

        QTcpSocket* clientSocket = server_->nextPendingConnection();
        queue_.push_back(clientSocket);

        connect(queue_.back(), &QTcpSocket::readyRead, this, &Server::slotReadClient);
        connect(queue_.back(), &QTcpSocket::stateChanged, this, &Server::slotUpdateListUsers);

        if (queue_.size() == RequairedPlayersForGame) {
            createGame_();
        }

        setStatus_("green");
        slotUpdateListUsers();
    }
}

void Server::closeAllConnections_() {
    if(isListening_){
        foreach(QTcpSocket* i, queue_) {
            i->close();
            delete i;
        }
        queue_.clear();

        foreach(Game* i, games_) {
            delete i;
        }
        games_.clear();

        server_->close();
        isListening_ = false;

        qDebug() << "Server has been stopped!";
    }
}


void Server::createGame_() {
    QMap<size_t, QTcpSocket*> delivery;

    for (size_t i = 1; i <= RequairedPlayersForGame; ++i) {
        delivery.insert(i, queue_.front());
        disconnect(queue_.front(), &QTcpSocket::readyRead, this, &Server::slotReadClient);
        disconnect(queue_.front(), &QTcpSocket::stateChanged, this, &Server::slotUpdateListUsers);
        queue_.pop_front();
    }

    games_.push_back(new Game(delivery));
}

void Server::hasGotPack() {
    if (!history_.empty()) {
        qDebug() << history_.back().toString();
    }

    //Maybe send in answer something
}

///_________________Visual__________________///
void Server::setStatus_(QString color){
    ui->status->setStyleSheet("background-color: " + color + ";");
}

void Server::slotUpdateListUsers() {
    ui->listUsers->clear();
    foreach(QTcpSocket* i, queue_) {
        if (i->state() == QAbstractSocket::ConnectedState) {
            ui->listUsers->addItem("id: " + QString::number(queue_.back()->socketDescriptor()));
        }
    }
}

