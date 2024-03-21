#include "Warlock.h"
#include "EntityBrain.h"

#define ENTITY_SHAPE_SUPPORT_PATH "Entities/Warlock_0.png"
#define ENTITY_SHAPE_SUPPORT_SIZE Vector2f(100,100)

Warlock::Warlock(const Vector2f& _position, const int _level) :
	Entity("Warlock", ShapeData(_position, ENTITY_SHAPE_SUPPORT_SIZE, ENTITY_SHAPE_SUPPORT_PATH))
{
	data = new EntityData(6, -3, 4, 8, 2, _level);
	brain = new EntityBrain(this);
	UpdateData();
}
