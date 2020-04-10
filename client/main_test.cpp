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
    window = new Client;
    window->show();
    Game* game = new Game(window);
    Map* map = new Map(game);
    Tile* tile = new Tile(map);
    Building* castle = tile->CreateBuilding(BuildingType::CastleType);
    Building* barracks = tile->CreateBuilding(BuildingType::BarracksType);
    Building* mine = tile->CreateBuilding(BuildingType::MineType);
    Building* fort = tile->CreateBuilding(BuildingType::FortType);
    ASSERT_EQ(castle->GetProducedMoney(), 5);
    ASSERT_EQ(barracks->GetProducedMoney(), 0);
    ASSERT_EQ(mine->GetProducedMoney(), 2);
    ASSERT_EQ(fort->GetProducedMoney(), 0);
}

TEST_F(TestMainWindow, test2){
    window = new Client;
    window->show();
    Game* game = new Game(window);
    Map* map = new Map(game);
    Tile* tile = new Tile(map);
    Castle* castle = new Castle(tile);
    castle->UnitCreationOrder(UnitType::ArcherType);
    ASSERT_TRUE(castle->UnitCreationTick() == nullptr);
    ASSERT_FALSE(castle->UnitCreationTick() == nullptr);
    castle->UnitCreationOrder(UnitType::HorsemanType);
    ASSERT_TRUE(castle->UnitCreationTick() == nullptr);
    ASSERT_TRUE(castle->UnitCreationTick() == nullptr);
    ASSERT_FALSE(castle->UnitCreationTick() == nullptr);
    castle->UnitCreationOrder(UnitType::SwordsmanType);
    ASSERT_FALSE(castle->UnitCreationTick() == nullptr);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
