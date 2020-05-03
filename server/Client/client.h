#ifndef CLIENT_H
#define CLIENT_H

#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTcpSocket>
#include <iostream>

class Client : public QObject
{
    Q_OBJECT
private:
    QTcpSocket* socket_;
    const unsigned port_ = 9998;
    const QString host_name_ = "127.0.0.5";

    QString recieveData_();
    void sendData_(const QString arrBlock);

public:
    Client();
    ~Client();

private slots:
    void slotRead();
    void slotCurrentState();
    void slotErrorSocket(QAbstractSocket::SocketError);
    void slotConnected();
    void slotDisconnected();

};

#endif // CLIENT_H
