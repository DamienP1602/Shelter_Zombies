#include "Armory.h"

#define BUILDING_SHAPE_ARMORY_PATH "GPE/Building/Armory.png"
#define BUILDING_SHAPE_ARMORY_SIZE Vector2f(500,500)

Armory::Armory(const Vector2f& _position) :
	Building("Armory", ShapeData(_position, BUILDING_SHAPE_ARMORY_SIZE, BUILDING_SHAPE_ARMORY_PATH))
{
	data = new BuildingData(30, 10, BonusType::Entity_DefenseBonus);
}
