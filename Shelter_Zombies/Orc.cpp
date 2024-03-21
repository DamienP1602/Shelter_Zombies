#include "Orc.h"
#include "EntityBrain.h"

#define ENTITY_SHAPE_SHOOTER_PATH "Entities/Orc_0.png"
#define ENTITY_SHAPE_SHOOTER_SIZE Vector2f(100,100)

Orc::Orc(const Vector2f& _position, const int _level) :
	Entity("Orc", ShapeData(_position, ENTITY_SHAPE_SHOOTER_SIZE, ENTITY_SHAPE_SHOOTER_PATH))
{
	data = new EntityData(5, 2, 2, 3, 5, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

