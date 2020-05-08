#include "button.h"

Button::Button(QWidget* parent) : QPushButton(parent){
    setMaximumSize(QWIDGETSIZE_MAX,QWIDGETSIZE_MAX);
    setMinimumSize(0,0);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding,  QSizePolicy::Expanding));
}

Action* Button::GetAction(){
    return _action;
}

void Button::SetAction(Action* action){
    _action = action;
}
