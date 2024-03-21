#include "Orc.h"
#include "EntityBrain.h"
#include "EnemyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SHOOTER_PATH "Entities/Orc_0.png"
#define ENTITY_SHAPE_SHOOTER_SIZE Vector2f(75.f,75.f)

Orc::Orc(const Vector2f& _position, const int _level) :
	Entity("Orc", ShapeData(_position, ENTITY_SHAPE_SHOOTER_SIZE, ENTITY_SHAPE_SHOOTER_PATH))
{
	data = new EntityData(5, 2, 2, .3f, 400, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Orc::~Orc()
{
	EnemyEntityManager::GetInstance().Remove(this);
}

void Orc::Init()
{
	const float _speed = 0.2f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(0.0, 0.0f), Vector2f(100.0, 100.0f), READ_RIGHT, true, 6, _speed),
	AnimationData("Movement", Vector2f(0.0f, 100.0f), Vector2f(90.0, 90.0f), READ_RIGHT, false, 6, _speed, "Idle"),
	AnimationData("Attack", Vector2f(0.0f, 200.0f), Vector2f(90.0, 90.0f), READ_RIGHT, false, 9, _speed, "Idle"),
	AnimationData("Death", Vector2f(10.0f, 300.0f), Vector2f(82.0, 94.0f), READ_RIGHT, false, 1, _speed),
		});
}

