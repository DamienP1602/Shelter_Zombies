#include "Workshop.h"

#define BUILDING_SHAPE_WORKSHOP_PATH ""
#define BUILDING_SHAPE_WORKSHOP_SIZE Vector2f()

Workshop::Workshop(const Vector2f& _position):
	Building("Workshop", ShapeData(_position, BUILDING_SHAPE_WORKSHOP_SIZE, BUILDING_SHAPE_WORKSHOP_PATH))
{
	data = new BuildingData(30,60, BonusType::Construction_DefenseBonus);
}
