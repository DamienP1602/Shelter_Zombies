#include "Artillery.h"

#define ENTITY_SHAPE_ARTILLERY_PATH ""
#define ENTITY_SHAPE_ARTILLERY_SIZE Vector2f()

Artillery::Artillery(const Vector2f& _position) :
	Entity("Artillery", ShapeData(_position, ENTITY_SHAPE_ARTILLERY_SIZE, ENTITY_SHAPE_ARTILLERY_PATH))
{
	data = new EntityData(3, 8, 1, 10, 0);
}

void Artillery::Movement()
{
}

void Artillery::Action()
{
	target->TakeDamage(data->damagePoint);
}
