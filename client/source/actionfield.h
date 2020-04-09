#ifndef ACTIONFIELD_H
#define ACTIONFIELD_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QGridLayout>
#include <QVector>

#include "actionbutton.h"

class ActionField : public QWidget
{
    Q_OBJECT
public:
    explicit ActionField(QWidget *parent = nullptr);
    void NewMenu();
    ActionButton* AddAction(QString name);
    void Pop();
    void Purge();
    void Refresh();
protected:
    void paintEvent(QPaintEvent *);
    QVector<QGridLayout*> _actionmenus;

signals:

};

#endif // ACTIONFIELD_H
