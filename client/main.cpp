#include "client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client w;
    w.show();
    //через ui
    w.setFixedSize(942, 636);
    return a.exec();
}
