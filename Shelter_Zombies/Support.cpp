#include "Support.h"

#define ENTITY_SHAPE_SUPPORT_PATH ""
#define ENTITY_SHAPE_SUPPORT_SIZE Vector2f()

Support::Support(const Vector2f& _position):
	Entity("Support", ShapeData(_position, ENTITY_SHAPE_SUPPORT_SIZE, ENTITY_SHAPE_SUPPORT_PATH))
{
	data = new EntityData(6, 3, 8, 2, 0);
}

void Support::Movement()
{
}

void Support::Action()
{
	target->Healing(data->damagePoint);
}
