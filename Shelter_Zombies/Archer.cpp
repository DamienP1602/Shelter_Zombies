#include "Archer.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SHOOTER_PATH "Animations/Archer_sheet.png"
#define ENTITY_SHAPE_SHOOTER_SIZE Vector2f(75.f, 75.f)

Archer::Archer(const Vector2f& _position, const int _level) :
	Entity("Archer", true, ShapeData(_position, ENTITY_SHAPE_SHOOTER_SIZE, ENTITY_SHAPE_SHOOTER_PATH, IntRect(1, 3, 25, 25)),CT_CONSTRUCTION)
{
	data = new EntityData(5, 2, 2, .3f, 400, _level);
	brain = new EntityBrain(this);
	UpdateData();
	Init();
}

void Archer::Init()
{
	const float _speed = 0.1f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(1.0, 3.0f), Vector2f(25.0, 25.0f), READ_RIGHT, true, 3, _speed),
	AnimationData("Movement", Vector2f(33.0f, 0.0f), Vector2f(26.0, 30.0f), READ_RIGHT, true, 2, _speed),
	AnimationData("Attack", Vector2f(1.0f, 2.0f), Vector2f(26.0, 28.0f), READ_RIGHT, false, 5, _speed, "Idle"),
	AnimationData("Death", Vector2f(64.0f, 3.0f), Vector2f(26.0, 26.0f), READ_RIGHT, false, 4, _speed),
		});
}
