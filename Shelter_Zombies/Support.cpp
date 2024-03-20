#include "Support.h"

#define ENTITY_SHAPE_SUPPORT_PATH "Entities/Church_0.png"
#define ENTITY_SHAPE_SUPPORT_SIZE Vector2f(100,100)

Support::Support(const Vector2f& _position):
	Entity("Support", ShapeData(_position, ENTITY_SHAPE_SUPPORT_SIZE, ENTITY_SHAPE_SUPPORT_PATH))
{
	data = new EntityData(6, -3, 4, 8, 2, 0);
	UpdateData();
}