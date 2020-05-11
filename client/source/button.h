#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include "tilecontent/units/action.h"

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget* parent = nullptr);
    Action GetAction();
    void SetAction(const Action& action);
private:
    Action _action;
};

#endif // BUTTON_H
