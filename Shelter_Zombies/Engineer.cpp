#include "Engineer.h"

#define BUILDING_SHAPE_ENGINEER_PATH "GPE/Building/Engineer.png"
#define BUILDING_SHAPE_ENGINEER_SIZE Vector2f(500,500)

Engineer::Engineer(const Vector2f& _position) :
	Building("Engineer", ShapeData(_position, BUILDING_SHAPE_ENGINEER_SIZE, BUILDING_SHAPE_ENGINEER_PATH))
{
	data = new BuildingData(30, 10, BonusType::Construction_AttackBonus);
}