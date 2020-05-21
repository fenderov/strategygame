#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLayout>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);
};

#endif // WIDGET_H
