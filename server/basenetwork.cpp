#include "basenetwork.h"

BaseNetwork::BaseNetwork(QWidget* parent) :
    QMainWindow(parent) {}

void BaseNetwork::send_(QTcpSocket *sock, const NetworkPackage& pack){
    QByteArray  bytes;
    QDataStream out(&bytes, QIODevice::WriteOnly);

    out << quint16(0) << pack ///

    out.device()->seek(0);
    out << quint16(bytes.size() - sizeof(quint16));

    sock->write(bytes);
}

void BaseNetwork::multySend_(QList<QTcpSocket*> list, const NetworkPackage& pack) {
    foreach(QTcpSocket* sock, list) {
        send_(sock, pack);
    }
}

void BaseNetwork::slotReadClient() {
    QTcpSocket* socket = static_cast<QTcpSocket*>(QObject::sender());

    QDataStream in(socket);
    quint16 blockSize = 0;
    while(true){
        if (blockSize == 0) {
            if (size_t(socket->bytesAvailable()) < sizeof(quint16)) break;
            in >> blockSize;
        }
        if (socket->bytesAvailable() < blockSize) break;
        QString message;
        in >> message;
        qDebug() << "We have got a string: " << message;
        blockSize = 0;
    }

    history_.push_back(pack);
    hasGotPack();
}
