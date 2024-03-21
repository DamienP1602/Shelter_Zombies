#include "Knight.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_FIGHTER_PATH "Entities/Knight_0.png"
#define ENTITY_SHAPE_FIGHTER_SIZE Vector2f(100,100)

Knight::Knight(const Vector2f& _position, const int _level) :
	Entity("Knight", ShapeData(_position, ENTITY_SHAPE_FIGHTER_SIZE, ENTITY_SHAPE_FIGHTER_PATH))
{
	data = new EntityData(10, 4, 1, 3, 1, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Knight::~Knight()
{
	AllyEntityManager::GetInstance().Remove(this);
	ActorManager::GetInstance().Remove(this);
}
