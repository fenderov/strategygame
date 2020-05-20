#include "army.h"

Army::Army() : _united(false) {
    Divide();
}

Army::~Army(){
    for(auto unit: _units){
        delete unit;
    }
}

bool Army::IsEmpty() const{
    return _units.empty();
}

void Army::AddUnit(Unit *unit){
    _units.push_back(unit);
}

unsigned int Army::GetPower() const{
    unsigned int power = 0;
    for(int i = 0; i < _units.size(); ++i){
        power += _units[i]->GetCombatPower();
    }
    return power;
}

void Army::Unite(){
    QVector<QString> actions;
    actions.push_back("army move");
    actions.push_back("army attack");
    actions.push_back("divide");
    SetPossibleActions(actions);
    _united = true;
}

void Army::Divide(){
    QVector<QString> actions;
    actions.push_back("browse units");
    actions.push_back("unite");
    SetPossibleActions(actions);
    _united = false;
}

Action Army::HandleAction(const Action &action){
    if(action.name == "unite"){
        Unite();
        return Action(id, "purge");
    }
    if(action.name == "divide"){
        Divide();
        return Action(id, "purge");
    }
    return Action(id, "purge");
}

QPixmap Army::GetImage(){
    if(IsEmpty()) return QPixmap();
    QPixmap armypixmap(48, 48);
    armypixmap.fill(Qt::transparent);
    QPixmap uimage;

    QPainter painter(&armypixmap);
    if(_units.size() >= 3){
        uimage = QPixmap(32, 32);
        uimage.fill(QColor(255, 100, 100));
        painter.drawPixmap(0, 0, 32, 32, uimage);
        uimage = _units[2]->GetImage();
        painter.drawPixmap(0, 0, 32, 32, uimage);
    }
    if(_units.size() >= 2){
        uimage = QPixmap(32, 32);
        uimage.fill(QColor(255, 140, 140));
        painter.drawPixmap(8, 8, 32, 32, uimage);
        uimage = _units[1]->GetImage();
        painter.drawPixmap(8, 8, 32, 32, uimage);
    }
    if(_units.size() >= 1){
        uimage = QPixmap(32, 32);
        uimage.fill(QColor(255, 180, 180));
        painter.drawPixmap(16, 16, 32, 32, uimage);
        uimage = _units[0]->GetImage();
        painter.drawPixmap(16, 16, 32, 32, uimage);
    }
    if(_units.size() >= 4 && _units.size() <= 10){
        uimage = QPixmap("images/numbers/num" + QString::number(_units.size()) +".png");
        painter.drawPixmap(32, 32, 16, 16, uimage);
    }
    return armypixmap;
}

void Army::Damage(int power){
    while(power >= _units.front()->GetPower()){
        power -= _units.front()->GetPower();
        delete _units.front();
        _units.pop_front();
        if(_units.empty()) return;
    }
    _units.front()->PureDamage(power);
}
