#include "Workshop.h"

#define BUILDING_SHAPE_WORKSHOP_PATH "GPE/Building/Workshop.png"
#define BUILDING_SHAPE_WORKSHOP_SIZE Vector2f(200.f,200.f)

Workshop::Workshop(const Vector2f& _position):
	Building("Workshop", ShapeData(_position, BUILDING_SHAPE_WORKSHOP_SIZE, BUILDING_SHAPE_WORKSHOP_PATH))
{
	data = new BuildingData(30, 10, BonusType::Construction_DefenseBonus);
}
