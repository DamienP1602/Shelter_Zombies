#include "Priest.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SUPPORT_PATH "Entities/Church_0.png"
#define ENTITY_SHAPE_SUPPORT_SIZE Vector2f(75.f,75.f)

Priest::Priest(const Vector2f& _position, const int _level) :
	Entity("Church", ShapeData(_position, ENTITY_SHAPE_SUPPORT_SIZE, ENTITY_SHAPE_SUPPORT_PATH))
{
	data = new EntityData(6, -3, 4, .8f, 300, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Priest::~Priest()
{
	AllyEntityManager::GetInstance().Remove(this);
}

void Priest::Init()
{
	const float _speed = 0.2f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(4.0, 3.0f), Vector2f(35.0, 49.0f), READ_RIGHT, true, 2, _speed),
	AnimationData("Movement", Vector2f(3.0f, 58.0f), Vector2f(33.0, 49.0f), READ_RIGHT, false, 4, _speed, "Idle"),
	AnimationData("Attack", Vector2f(0.0f, 112.0f), Vector2f(47.0, 49.0f), READ_RIGHT, false, 2, _speed, "Idle"),
	AnimationData("Death", Vector2f(2.0f, 167.0f), Vector2f(51.0, 30.0f), READ_RIGHT, false, 1, _speed),
		});
}
