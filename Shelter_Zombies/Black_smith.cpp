#include "Black_smith.h"

#define BUILDING_SHAPE_BLACK_SMITH_PATH ""
#define BUILDING_SHAPE_BLACK_SMITH_SIZE Vector2f()

Black_smith::Black_smith(const Vector2f& _position) :
	Building("Black_smith", ShapeData(_position, BUILDING_SHAPE_BLACK_SMITH_SIZE, BUILDING_SHAPE_BLACK_SMITH_PATH))
{
	data = new BuildingData(30, 10, BonusType::Entity_AttackBonus);
}
