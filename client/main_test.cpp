#include "main_test.h"

void TestMainWindow::SetUp()
{
    app = new QApplication(argc, argv);
}
void TestMainWindow::TearDown()
{
    delete app;
    //app->exec();
}

TEST_F(TestMainWindow, test1){
    //window = new Client;
    //window->show();
    Game* game = new Game();
    Tile* tile0 = game->GetMap()->GetTile(0,0);
    Tile* tile1 = game->GetMap()->GetTile(0,1);
    Tile* tile2 = game->GetMap()->GetTile(1,0);
    Tile* tile3 = game->GetMap()->GetTile(1,1);
    tile0->SetBuilding(BuildingType::CastleType);
    tile1->SetBuilding(BuildingType::BarracksType);
    tile2->SetBuilding(BuildingType::MineType);
    tile3->SetBuilding(BuildingType::FortType);
    ASSERT_EQ(tile0->GetBuilding()->GetProducedMoney(), 5);
    ASSERT_EQ(tile1->GetBuilding()->GetProducedMoney(), 0);
    ASSERT_EQ(tile2->GetBuilding()->GetProducedMoney(), 2);
    ASSERT_EQ(tile3->GetBuilding()->GetProducedMoney(), 0);
    delete game; //Вызывает деструкторы для всего что создалось
}

TEST_F(TestMainWindow, test2){
    //window = new Client;
    //window->show();
    Castle* castle = new Castle();
    castle->UnitCreationOrder(UnitType::ArcherType);
    ASSERT_TRUE(castle->UnitCreationTick() == nullptr);
    ASSERT_FALSE(castle->UnitCreationTick() == nullptr);
    castle->UnitCreationOrder(UnitType::HorsemanType);
    ASSERT_TRUE(castle->UnitCreationTick() == nullptr);
    ASSERT_TRUE(castle->UnitCreationTick() == nullptr);
    ASSERT_FALSE(castle->UnitCreationTick() == nullptr);
    castle->UnitCreationOrder(UnitType::SwordsmanType);
    ASSERT_FALSE(castle->UnitCreationTick() == nullptr);
    delete castle;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
