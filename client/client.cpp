#include "client.h"
#include "./ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    Game* game = new Game(this);
    centralWidget()->layout()->addWidget(game);
}

Client::~Client()
{
    delete ui;
}

