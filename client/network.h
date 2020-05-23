#ifndef NETWORK_H
#define NETWORK_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QTime>

namespace Ui {
class Network;
}

class Network : public QMainWindow
{
    Q_OBJECT

public:
    explicit Network(QWidget *parent = 0);
    ~Network();

private slots:
    void on_connectbutton_clicked();
    void connected();

private:
    Ui::Network *ui;
    QTcpSocket* _socket;
    bool _connected;
    void setStatus(QString color);
    QVector<QTcpSocket*> clients;

signals:
    void netconnected(QTcpSocket* socket);
};

#endif // NETWORK_H
