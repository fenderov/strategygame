#ifndef ACTIONFIELD_H
#define ACTIONFIELD_H

#include <QHBoxLayout>
#include <QString>

#include "widget.h"
#include "button.h"
#include "tilecontent/units/action.h"

class ActionField : public Widget
{
    Q_OBJECT
public:
    explicit ActionField(QWidget *parent = nullptr);
    void NewMenu();
    Button* AddAction(Action* action);
};

#endif // ACTIONFIELD_H
