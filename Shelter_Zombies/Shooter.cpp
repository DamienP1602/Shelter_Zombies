#include "Shooter.h"

#define ENTITY_SHAPE_SHOOTER_PATH "Entities/Archer_0.png"
#define ENTITY_SHAPE_SHOOTER_SIZE Vector2f(100,100)

Shooter::Shooter(const Vector2f& _position) :
	Entity("Shooter", ShapeData(_position, ENTITY_SHAPE_SHOOTER_SIZE, ENTITY_SHAPE_SHOOTER_PATH))
{
	data = new EntityData(5, 2, 2, 3, 5, 0);
	UpdateData();
}
