#include "Skelet.h"
#include "EntityBrain.h"
#include "EnemyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_FIGHTER_PATH "Entities/Skelet_0.png"
#define ENTITY_SHAPE_FIGHTER_SIZE Vector2f(75.f,75.f)

Skelet::Skelet(const Vector2f& _position, const int _level) :
	Entity("Skelet", ShapeData(_position, ENTITY_SHAPE_FIGHTER_SIZE, ENTITY_SHAPE_FIGHTER_PATH))
{
	data = new EntityData(10, 4, 1, .3f, 100, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Skelet::~Skelet()
{
	EnemyEntityManager::GetInstance().Remove(this);
}

void Skelet::Init()
{
	const float _speed = 0.2f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(0.0, 0.0f), Vector2f(43.0, 37.0f), READ_RIGHT, true, 4, _speed),
	AnimationData("Movement", Vector2f(0.0f, 42.0f), Vector2f(36.0, 33.0f), READ_RIGHT, false, 8, _speed, "Idle"),
	AnimationData("Attack", Vector2f(0.0f, 88.0f), Vector2f(45.0, 53.0f), READ_RIGHT, false, 5, _speed, "Idle"),
	AnimationData("Death", Vector2f(2.0f, 133.0f), Vector2f(32.0, 20.0f), READ_RIGHT, false, 2, _speed),
		});
}
