#include "Archer.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SHOOTER_PATH "Entities/Archer_0.png"
#define ENTITY_SHAPE_SHOOTER_SIZE Vector2f(100,100)

Archer::Archer(const Vector2f& _position, const int _level) :
	Entity("Archer", ShapeData(_position, ENTITY_SHAPE_SHOOTER_SIZE, ENTITY_SHAPE_SHOOTER_PATH))
{
	data = new EntityData(5, 2, 2, 3, 5, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Archer::~Archer()
{
	AllyEntityManager::GetInstance().Remove(this);
	ActorManager::GetInstance().Remove(this);
}
