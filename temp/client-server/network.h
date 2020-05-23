#ifndef NETWORK_H
#define NETWORK_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QTime>

#include <basenetwork.h>

enum Mode{
    None,
    Server,
    Client
};

namespace Ui {
class Network;
}

class Network : public BaseNetwork
{
    Q_OBJECT

public:
    explicit Network(QWidget *parent = 0);
    ~Network();

private slots:
    void on_connectbutton_clicked();
    void on_sendbutton_clicked();

    void connected();

private:
    Ui::Network *ui;
    QTcpSocket* socket;
    quint16 blocksize;
    Mode mode;
    void setStatus(QString color);

    void hasGotPack() override;
};

#endif // NETWORK_H
