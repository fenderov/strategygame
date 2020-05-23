#include "buildinglist.h"

Castle::Castle() : _income(5){
    _image = QPixmap("images/castle.png");
    QVector<QString> actions;
    actions.push_back("browse create unit");
    SetPossibleActions(actions);
}

Barracks::Barracks(){
    _image = QPixmap("images/barracks.png");
    QVector<QString> actions;
    actions.push_back("browse create unit");
    SetPossibleActions(actions);
}

Mine::Mine() : _income(2){
    _image = QPixmap("images/mine.png");
}

Fort::Fort(){
    _image = QPixmap("images/fort.png");
}

Unit* Castle::GetProducedUnits(){
    return UnitCreationTick();
}

unsigned char Castle::GetProducedMoney(){
    return _income;
}

Action Castle::HandleAction(const Action& action){
    if(action.name == "create unit");
    int concrete = action.params[0];
    if(concrete == 1){
        UnitCreationOrder(SwordsmanType);
    }
    if(concrete == 2){
        UnitCreationOrder(ArcherType);
    }
    if(concrete == 3){
        UnitCreationOrder(HorsemanType);
    }
    return Action(id, "purge");
}

float Castle::GetDefenceBonus() const{
    return 1.4;
}

float Castle::GetAttackBonus() const{
    return 1.1;
}

Unit* Barracks::GetProducedUnits(){
    return UnitCreationTick();
}

unsigned char Barracks::GetProducedMoney(){
    return 0;
}

Action Barracks::HandleAction(const Action& action){
    if(action.name == "create unit");
    int concrete = action.params[0];
    if(concrete == 1){
        UnitCreationOrder(SwordsmanType);
    }
    if(concrete == 2){
        UnitCreationOrder(ArcherType);
    }
    if(concrete == 3){
        UnitCreationOrder(HorsemanType);
    }
    action;
    return Action(id, "purge");
}

float Barracks::GetDefenceBonus() const{
    return 1.2;
}

float Barracks::GetAttackBonus() const{
    return 1;
}


Unit* Mine::GetProducedUnits(){
    return nullptr;
}

unsigned char Mine::GetProducedMoney(){
    return _income;
}

Action Mine::HandleAction(const Action& action){
    //error
    return Action(id, "purge");
}

float Mine::GetDefenceBonus() const{
    return 1;
}

float Mine::GetAttackBonus() const{
    return 1.4;
}


Unit* Fort::GetProducedUnits(){
    return nullptr;
}

unsigned char Fort::GetProducedMoney(){
    return 0;
}

Action Fort::HandleAction(const Action& action){
    //error
    return Action(id, "purge");
}

float Fort::GetDefenceBonus() const{
    return 1.4;
}

float Fort::GetAttackBonus() const{
    return 0.9;
}

