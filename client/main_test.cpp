#include "main_test.h"

void TestMainWindow::SetUp()
{
    app = new QApplication(argc, argv);
}
void TestMainWindow::TearDown()
{
    //app->exec();
}

TEST_F(TestMainWindow, test1){
    window = new Client;
    window->show();
    //ASSERT_EQ(window->myadd(3, 4), 7);
}

TEST_F(TestMainWindow, test2){
    window = new Client;
    /*window->customwidget = new widgetclass;
    window->show();
    ASSERT_EQ(window->customwidget->mymultiply(3, 5), 15);*/
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
