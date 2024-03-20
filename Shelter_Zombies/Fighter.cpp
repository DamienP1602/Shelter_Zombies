#include "Fighter.h"

#define ENTITY_SHAPE_FIGHTER_PATH ""
#define ENTITY_SHAPE_FIGHTER_SIZE Vector2f()

Fighter::Fighter(const Vector2f& _position) : 
	Entity("Fighter", ShapeData(_position, ENTITY_SHAPE_FIGHTER_SIZE, ENTITY_SHAPE_FIGHTER_PATH))
{
	data = new EntityData(10, 4, 1, 3, 1, 0);
	UpdateData();
}
