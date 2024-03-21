#include "Skelet.h"
#include "EntityBrain.h"
#include "EnemyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_FIGHTER_PATH "Entities/Skelet_0.png"
#define ENTITY_SHAPE_FIGHTER_SIZE Vector2f(100,100)

Skelet::Skelet(const Vector2f& _position, const int _level) :
	Entity("Skelet", ShapeData(_position, ENTITY_SHAPE_FIGHTER_SIZE, ENTITY_SHAPE_FIGHTER_PATH))
{
	data = new EntityData(10, 4, 1, 3, 1, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Skelet::~Skelet()
{
	EnemyEntityManager::GetInstance().Remove(this);
	ActorManager::GetInstance().Remove(this);
}
