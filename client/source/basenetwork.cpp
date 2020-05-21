#include "basenetwork.h"

BaseNetwork::BaseNetwork(QWidget* parent) :
    QWidget(parent),
    nextBlockSize(0) {}

void BaseNetwork::send_(QTcpSocket *sock, const NetworkPackage& pack){
    QByteArray  bytes;
    QDataStream out(&bytes, QIODevice::WriteOnly);

    out << quint64(0) << pack;
    out.device()->seek(0);
    out << quint64(bytes.size() - sizeof(quint64));

    sock->write(bytes);
}

void BaseNetwork::slotReadClient() {
    QTcpSocket* socket = static_cast<QTcpSocket*>(QObject::sender());
    QDataStream in(socket);
    for(;;) {
        if (nextBlockSize == 0) {
            if (socket->bytesAvailable() < sizeof(quint64))
                break;
            in >> nextBlockSize;
        }

        if (socket->bytesAvailable() < nextBlockSize)
            break;

        nextBlockSize = 0;

        NetworkPackage pack;
        in >> pack;
        history_.push_back(pack);
        hasGotPack();
    }
}
