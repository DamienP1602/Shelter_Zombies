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

void Warlock::Init()
{
	const float _speed = 0.2f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(3.0, 3.0f), Vector2f(36.0, 56.0f), READ_RIGHT, true, 1, _speed),
	AnimationData("Movement", Vector2f(3.0f, 65.0f), Vector2f(36.0, 56.0f), READ_RIGHT, false, 2, _speed, "Idle"),
	AnimationData("Attack", Vector2f(1.0f, 128.0f), Vector2f(40.0, 58.0f), READ_RIGHT, false, 2, _speed, "Idle"),
	AnimationData("Death", Vector2f(3.0f, 190.0f), Vector2f(36.0, 56.0f), READ_RIGHT, false, 1, _speed),
		});
}
