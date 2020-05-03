#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

#include "tilecontent/units/action.h"

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QWidget* parent);
    Action* GetAction();
    void SetAction(Action* action);
private:
    Action* _action;
};

#endif // BUTTON_H
