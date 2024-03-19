#include "Canteen.h"

#define BUILDING_SHAPE_CANTEEN_PATH ""
#define BUILDING_SHAPE_CANTEEN_SIZE Vector2f()

Canteen::Canteen(const Vector2f& _position) :
	Building("Canteen", ShapeData(_position, BUILDING_SHAPE_CANTEEN_SIZE, BUILDING_SHAPE_CANTEEN_PATH))
{
	data = new BuildingData(30, BonusType::Entity_SpeedBonus);
}