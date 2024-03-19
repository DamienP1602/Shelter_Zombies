#include "Nexus.h"

#define BUILDING_SHAPE_NEXUS_PATH ""
#define BUILDING_SHAPE_NEXUS_SIZE Vector2f()

Nexus::Nexus(const Vector2f& _position):
	Building("Nexus", ShapeData(_position, BUILDING_SHAPE_NEXUS_SIZE, BUILDING_SHAPE_NEXUS_PATH))
{
	data = new BuildingData(100, BonusType::None);
}