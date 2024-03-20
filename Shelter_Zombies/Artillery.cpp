#include "Artillery.h"

#define ENTITY_SHAPE_ARTILLERY_PATH "Entities/Catapult_0.png"
#define ENTITY_SHAPE_ARTILLERY_SIZE Vector2f(100,100)

Artillery::Artillery(const Vector2f& _position) :
	Entity("Artillery", ShapeData(_position, ENTITY_SHAPE_ARTILLERY_SIZE, ENTITY_SHAPE_ARTILLERY_PATH))
{
	data = new EntityData(3, 8, 6, 1, 10, 0);
	UpdateData();
}
