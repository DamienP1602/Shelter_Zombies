#include "Nexus.h"

#define BUILDING_SHAPE_NEXUS_PATH "GPE/Building/Nexus.png"
#define BUILDING_SHAPE_NEXUS_SIZE Vector2f(50.0f,50.0f)

Nexus::Nexus(const Vector2f& _position):
	Building("Nexus", ShapeData(_position, BUILDING_SHAPE_NEXUS_SIZE, BUILDING_SHAPE_NEXUS_PATH))
{
	data = new BuildingData(100, 0, BonusType::None);
}