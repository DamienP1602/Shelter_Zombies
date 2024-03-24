#include "Orc.h"
#include "EntityBrain.h"
#include "EnemyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SHOOTER_PATH "Animations/Orc_sheet.png"
#define ENTITY_SHAPE_SHOOTER_SIZE Vector2f(75.f,75.f)

Orc::Orc(const Vector2f& _position, const int _level) :
	Entity(STRING_ID("Orc"), false, ShapeData(_position, ENTITY_SHAPE_SHOOTER_SIZE, ENTITY_SHAPE_SHOOTER_PATH, IntRect(0, 0, 100, 100)), CT_CONSTRUCTION)
{
	data = new EntityData(5, 2, 2, .3f, 400, _level);
	brain = new EntityBrain(this);
	UpdateData();
	Init();
}

void Orc::Init()
{
	const float _speed = 0.1f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(0.0, 0.0f), Vector2f(100.0, 100.0f), READ_RIGHT, true, 6, _speed),
	AnimationData("Movement", Vector2f(0.0f, 100.0f), Vector2f(90.0, 90.0f), READ_RIGHT, true, 6, _speed),
	AnimationData("Attack", Vector2f(0.0f, 200.0f), Vector2f(90.0, 90.0f), READ_RIGHT, false, 9, _speed, "Idle"),
	AnimationData("Death", Vector2f(10.0f, 300.0f), Vector2f(82.0, 94.0f), READ_RIGHT, false, 1, _speed),
		});
}

