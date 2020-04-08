#include "client.h"
#include "./ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    setLayout(ui->mainlayout);
}

void Client::resizeEvent(QResizeEvent *event)
{
    int width = event->size().width();
    int height = event->size().height();
    int oldWidth = event->oldSize().width();
    int oldHeight = event->oldSize().height();

    if (width < oldWidth || height < oldHeight)
    {
        if (width > height)
        {
            resize(height, height);
        }
        else
        {
            resize(width, width);
        }
    }
    else
    {
        if (width > height)
        {
            resize(width, width);
        }
        else
        {
            resize(height, height);
        }
    }
}

Client::~Client()
{
    delete ui;
}

