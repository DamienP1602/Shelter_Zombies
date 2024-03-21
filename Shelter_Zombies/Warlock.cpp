#include "Warlock.h"
#include "EntityBrain.h"
#include "EnemyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SUPPORT_PATH "Entities/Warlock_0.png"
#define ENTITY_SHAPE_SUPPORT_SIZE Vector2f(75.f,75.f)

Warlock::Warlock(const Vector2f& _position, const int _level) :
	Entity("Warlock", ShapeData(_position, ENTITY_SHAPE_SUPPORT_SIZE, ENTITY_SHAPE_SUPPORT_PATH))
{
	data = new EntityData(6, -3, 4, .8f, 200, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Warlock::~Warlock()
{
	EnemyEntityManager::GetInstance().Remove(this);
}
