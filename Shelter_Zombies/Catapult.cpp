#include "Catapult.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_ARTILLERY_PATH "Entities/Catapult_0.png"
#define ENTITY_SHAPE_ARTILLERY_SIZE Vector2f(100,100)

Catapult::Catapult(const Vector2f& _position, const int _level) :
	Entity("Catapult", ShapeData(_position, ENTITY_SHAPE_ARTILLERY_SIZE, ENTITY_SHAPE_ARTILLERY_PATH))
{
	data = new EntityData(3, 8, 6, 1, 10, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Catapult::~Catapult()
{
	AllyEntityManager::GetInstance().Remove(this);
	ActorManager::GetInstance().Remove(this);
}
