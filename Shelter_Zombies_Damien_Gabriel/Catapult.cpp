#include "Catapult.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_ARTILLERY_PATH "Animations/Catapult_sheet.png"
#define ENTITY_SHAPE_ARTILLERY_SIZE Vector2f(75.f,75.f)

Catapult::Catapult(const Vector2f& _position, const int _level) :
	Entity("Catapult", true, ShapeData(_position, ENTITY_SHAPE_ARTILLERY_SIZE, ENTITY_SHAPE_ARTILLERY_PATH, IntRect(1, 0, 32, 36)), CT_CONSTRUCTION)
{
	data = new EntityData(3, 8, 6, .1f, 1000, _level);
	brain = new EntityBrain(this);
	UpdateData();
	Init();
}

void Catapult::Init()
{
	const float _speed = 0.1f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(1.0, 0.0f), Vector2f(32.0, 36.0f), READ_DOWN, true, 1, _speed),
	AnimationData("Movement", Vector2f(1.0f, 39.0f), Vector2f(38.0, 33.0f), READ_DOWN, true, 4, _speed),
	AnimationData("Attack", Vector2f(185.0f, 53.0f), Vector2f(39.0, 53.0f), READ_DOWN, false, 7, _speed, "Idle"),
	AnimationData("Death", Vector2f(2.0f, 128.0f), Vector2f(33.0, 36.0f), READ_DOWN, false, 1, _speed),
		});
}