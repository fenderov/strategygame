#ifndef BASENETWORK_H
#define BASENETWORK_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDataStream>

#include <sstream>

#include "networkpackage.h"

//#include "file with pack class"
///_________

class DUMMY {
public:
    friend std::ostream &operator<<(std::ostream &output, const DUMMY &D) {
        output << "HAHA";
        return output;
    }

    QString toString() const {
        std::stringstream ss;
        ss << *this;
        std::string s;
        ss >> s;
        return QString::fromUtf8(s.c_str());
    }
};

///_________

class BaseNetwork : public QMainWindow
{
    Q_OBJECT
public:
    BaseNetwork(QWidget* = nullptr);

protected slots:
    void slotReadClient();

protected:
    void send_(QTcpSocket*, const DUMMY&);
    void multySend_(QList<QTcpSocket*>, const DUMMY&);
    virtual void hasGotPack() = 0;

    QVector <DUMMY> history_;
};

#endif // BASENETWORK_H
