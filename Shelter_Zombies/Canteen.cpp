#include "Canteen.h"

#define BUILDING_SHAPE_CANTEEN_PATH "GPE/Building/Canteen.png"
#define BUILDING_SHAPE_CANTEEN_SIZE Vector2f(200.f,200.f)

Canteen::Canteen(const Vector2f& _position) :
	Building("Canteen", ShapeData(_position, BUILDING_SHAPE_CANTEEN_SIZE, BUILDING_SHAPE_CANTEEN_PATH))
{
	data = new BuildingData(30, 10, BonusType::Entity_SpeedBonus);
}