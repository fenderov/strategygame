#include "buildinglist.h"

Castle::Castle(QWidget *parent) : Building(parent){

}

Barracks::Barracks(QWidget *parent) : Building(parent){

}

Mine::Mine(QWidget *parent) : Building(parent){

}

Fort::Fort(QWidget *parent) : Building(parent){

}

void Castle::BrowseActions(ActionField* actionfield){
    actionfield->NewMenu();
    ActionButton* current = new ActionButton;

    current = actionfield->AddAction("Создать юнит");
    connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseBuildUnitActions(actionfield)));
}

void Barracks::BrowseActions(ActionField* actionfield){
    actionfield->NewMenu();
    ActionButton* current = new ActionButton;

    current = actionfield->AddAction("Создать юнит");
    connect(current, SIGNAL(ActionButton::clicked()), this, SLOT(BrowseBuildUnitActions(actionfield)));

}

void Mine::BrowseActions(ActionField* actionfield){
    //no actions now
}

void Fort::BrowseActions(ActionField* actionfield){
    //no actions now
}

Unit* Castle::GetProducedUnits(){
    return UnitCreationTick();
}

unsigned char Castle::GetProducedMoney(){
    return _income;
}

Unit* Barracks::GetProducedUnits(){
    return UnitCreationTick();
}

unsigned char Barracks::GetProducedMoney(){
    return 0;
}

Unit* Mine::GetProducedUnits(){
    return nullptr;
}

unsigned char Mine::GetProducedMoney(){
    return _income;
}

Unit* Fort::GetProducedUnits(){
    return nullptr;
}

unsigned char Fort::GetProducedMoney(){
    return 0;
}
