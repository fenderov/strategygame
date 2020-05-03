#include "button.h"

Button::Button(QWidget* parent) : QPushButton(parent){

}

Action* Button::GetAction(){
    return _action;
}

void Button::SetAction(Action* action){
    _action = action;
}
