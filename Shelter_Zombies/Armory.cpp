#include "Armory.h"

#define BUILDING_SHAPE_ARMORY_PATH ""
#define BUILDING_SHAPE_ARMORY_SIZE Vector2f()

Armory::Armory(const Vector2f& _position) :
	Building("Armory", ShapeData(_position, BUILDING_SHAPE_ARMORY_SIZE, BUILDING_SHAPE_ARMORY_PATH))
{
	data = new BuildingData(30,30, BonusType::Entity_DefenseBonus);
}
