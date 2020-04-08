#ifndef ACTIONFIELD_H
#define ACTIONFIELD_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

class ActionField : public QWidget
{
    Q_OBJECT
public:
    explicit ActionField(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif // ACTIONFIELD_H
