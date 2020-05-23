#ifndef ACTIONFIELD_H
#define ACTIONFIELD_H

#include <QHBoxLayout>
#include <QString>
#include <QVector>

#include "widget.h"
#include "button.h"
#include "tilecontent/units/action.h"

class ActionField : public Widget
{
    Q_OBJECT
public:
    explicit ActionField(QWidget *parent = nullptr);
    ~ActionField();
    void NewMenu();
    void Purge();
    void Pop();
    void AddButton(Button* button);
    bool IsEmpty();
private:
    struct Menu
    {
        QVector<Button*> buttons;
    };
    QVector<Menu*> _menus;
};

#endif // ACTIONFIELD_H
