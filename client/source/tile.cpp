#include "tile.h"

#include <iostream>

Tile::Tile(QWidget *parent) : Button(parent){
    _building = nullptr;
    _army = new Army;
    _owner = nullptr;
    _enabled = true;
    setStyleSheet("background-color: white;");
    int imagen = qrand()%4 + 1;
    if(imagen == 1){
        _image = QPixmap("images/field1.png");
        _imagedisabled = QPixmap("images/fielddisabled1.png");
    }
    if(imagen == 2){
        _image = QPixmap("images/field2.png");
        _imagedisabled = QPixmap("images/fielddisabled2.png");
    }
    if(imagen == 3){
        _image = QPixmap("images/field3.png");
        _imagedisabled = QPixmap("images/fielddisabled3.png");
    }
    if(imagen == 4){
        _image = QPixmap("images/field4.png");
        _imagedisabled = QPixmap("images/fielddisabled4.png");
    }
}

Tile::~Tile(){
    if(_army != nullptr) delete _army;
    if(_building != nullptr) delete _building;
}

void Tile::Tick(){
    if(_building != nullptr){
        Unit* unit = _building->GetProducedUnits();
        if(unit) _army->AddUnit(unit);
        //_owner->CangeMoney(_building->GetProducedMoney());
    }
    _army->Refresh();
    DrawEnabled();
}

bool Tile::IsArmyEmpty() const{
    return _army->IsEmpty();
}

bool Tile::BuildingExists() const{
    if(_building) return true;
    return false;
}

Army* Tile::GetArmy() const{
    return _army;
}

void Tile::SetArmy(Army* army) {
    _army = army;
}


Building* Tile::GetBuilding() const{
    return _building;
}

void Tile::ProduceMoney(unsigned char income){
   _owner->CangeMoney(income);
}

unsigned int Tile::GetAttackPower() const{
    int power = _army->GetPower() * _building->GetAttackBonus();
    return power;
}

unsigned int Tile::GetDefencePower() const{
    int power = _army->GetPower() * _building->GetDefenceBonus();
    return power;
}

Player* Tile::GetOwner() const{
    return _owner;
}
void Tile::SetOwner(Player* newOwner){
    _owner = newOwner;
}

void Tile::SetBuilding(BuildingType type){
    _building = CreateBuilding(type);
}

Action Tile::HandleAction(const Action& action){
    //error
    return Action(id, "purge");
}

void Tile::Highlight(){
    setStyleSheet("background-color: grey");
}

void Tile::Unhighlight(){
    setStyleSheet("background-color: white");
}

bool Tile::IsEnabled() const{
    return _enabled;
}

void Tile::DrawDisabled(){
    Draw(_imagedisabled);
    _enabled = false;
}

void Tile::DrawEnabled(){
    Draw(_image);
    _enabled = true;
}

void Tile::Draw(const QPixmap& img){
    if(_owner != nullptr){
        setStyleSheet("background-color: " + _owner->GetColor() + ";");
    }
    QPixmap tilepixmap = img;

    QPixmap bimage;
    if(_building) bimage = _building->GetImage();

    QPixmap aimage = _army->GetImage();

    QPainter painter(&tilepixmap);
    painter.drawPixmap(0, 0, 64, 64, bimage);
    painter.drawPixmap(8, 8, 48, 48, aimage);
    QIcon icon;
    icon.addPixmap(tilepixmap);
    setIcon(icon);
    setIconSize(QSize(64, 64));
}


int Tile::GetX() const{
    return _x;
}

int Tile::GetY() const{
    return _y;
}

int Tile::SetX(int x){
    _x = x;
}

int Tile::SetY(int y){
    _y = y;
}
