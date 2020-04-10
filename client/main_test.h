#include <gtest/gtest.h>
#include <QApplication>
#include "client.h"

class TestMainWindow : public ::testing::Test
{
protected:
    void SetUp();
    void TearDown();
    int argc = 0;
    char **argv = 0;
    Client *window;
    QApplication *app;
};
