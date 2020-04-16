#include "buildingfactory.h"

BuildingFactory::BuildingFactory()
{

}

Building* BuildingFactory::CreateBuilding(BuildingType type){
    switch(type){
    case BuildingType::CastleType:
        return new Castle();
    case BuildingType::BarracksType:
        return new Barracks();
    case BuildingType::MineType:
        return new Mine();
    case BuildingType::FortType:
        return new Fort();
    case BuildingType::BuildingTypeNull:
        return nullptr;
    }
}
