#include "client.h"

Client::Client()
{   
    socket_ = new QTcpSocket(this);

    connect(socket_, SIGNAL(readyRead()), this, SLOT(slotRead()));
    connect(socket_, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
    connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotErrorSocket(QAbstractSocket::SocketError)));
    connect(socket_, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slotCurrentState()));

    socket_->connectToHost(host_name_, port_);

}

Client::~Client()
{
    delete socket_;
}

void Client::slotCurrentState() {
    qDebug() << socket_->state();
}

void Client::slotErrorSocket(QAbstractSocket::SocketError err) {
    qDebug() << err;
}

void Client::slotRead() {
    qDebug() << recieveData_();
}

void Client::slotConnected() {
    qDebug() << "Has connected to server...";
}

void Client::slotDisconnected() {
    qDebug() << "Has disconnected from server...";
}

QString Client::recieveData_() {
    QDataStream in(socket_);
    QString data;
    in.setVersion(QDataStream::Qt_4_2);
    quint16 size_block = 0;
    for (;;) {
        if (!size_block) {
            if (socket_->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> size_block;
        }

        if (socket_->bytesAvailable() < size_block) {
            break;
        }

        QString str;
        in >> str;
        data += str;

        size_block = 0;
    }
    return data;
}

void Client::sendData_(const QString data) {
    QByteArray arrBlock;

    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);

    out << quint16(0) <<  data;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    socket_->write(arrBlock);
}
