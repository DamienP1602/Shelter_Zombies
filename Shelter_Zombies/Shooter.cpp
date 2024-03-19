#include "Shooter.h"

#define ENTITY_SHAPE_SHOOTER_PATH ""
#define ENTITY_SHAPE_SHOOTER_SIZE Vector2f()

Shooter::Shooter(const Vector2f& _position) :
Entity("Shooter", ShapeData(_position, ENTITY_SHAPE_SHOOTER_SIZE, ENTITY_SHAPE_SHOOTER_PATH))
{
	data = new EntityData(5, 2, 3, 5, 0);
}

void Shooter::Movement()
{
}

void Shooter::Action()
{
	target->TakeDamage(data->damagePoint);
}
