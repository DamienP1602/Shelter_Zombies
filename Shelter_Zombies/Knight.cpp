#include "Knight.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_FIGHTER_PATH "Entities/Knight_0.png"
#define ENTITY_SHAPE_FIGHTER_SIZE Vector2f(75.f,75.f)

Knight::Knight(const Vector2f& _position, const int _level) :
	Entity("Knight", ShapeData(_position, ENTITY_SHAPE_FIGHTER_SIZE, ENTITY_SHAPE_FIGHTER_PATH))
{
	data = new EntityData(10, 4, 1, .3f, 100, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Knight::~Knight()
{
	AllyEntityManager::GetInstance().Remove(this);
}

void Knight::Init()
{
	const float _speed = 0.2f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(4.0, 2.0f), Vector2f(17.0, 32.0f), READ_RIGHT, true, 1, _speed),
	AnimationData("Movement", Vector2f(33.0f, 3.0f), Vector2f(26.0, 30.0f), READ_RIGHT, false, 4, _speed, "Idle"),
	AnimationData("Attack", Vector2f(1.0f, 35.0f), Vector2f(32.0, 33.0f), READ_RIGHT, false, 3, _speed, "Idle"),
	AnimationData("Death", Vector2f(1.0f, 69.0f), Vector2f(31.0, 33.0f), READ_RIGHT, true, 3, _speed),
		});
}
