#ifndef BASENETWORK_H
#define BASENETWORK_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDataStream>

#include <sstream>

#include "networkpackage.h"

class BaseNetwork : public QMainWindow
{
    Q_OBJECT
public:
    BaseNetwork(QWidget* = nullptr);

protected slots:
    void slotReadClient();

protected:
    void send_(QTcpSocket*, const NetworkPackage&);
    void multySend_(QList<QTcpSocket*>, const NetworkPackage&);
    virtual void hasGotPack() = 0;

    QVector <NetworkPackage> history_;
};

#endif // BASENETWORK_H
