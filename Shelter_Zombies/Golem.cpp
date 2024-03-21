#include "Golem.h"
#include "EntityBrain.h"

#define ENTITY_SHAPE_ARTILLERY_PATH "Entities/Golem_0.png"
#define ENTITY_SHAPE_ARTILLERY_SIZE Vector2f(100,100)

Golem::Golem(const Vector2f& _position, const int _level) :
	Entity("Golem", ShapeData(_position, ENTITY_SHAPE_ARTILLERY_SIZE, ENTITY_SHAPE_ARTILLERY_PATH))
{
	data = new EntityData(3, 8, 6, 1, 10, _level);
	brain = new EntityBrain(this);
	UpdateData();
}
