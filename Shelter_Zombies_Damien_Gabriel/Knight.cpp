#include "Knight.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_FIGHTER_PATH "Animations/Knight_sheet.png"
#define ENTITY_SHAPE_FIGHTER_SIZE Vector2f(75.f,75.f)

Knight::Knight(const Vector2f& _position, const int _level) :
	Entity("Knight", true, ShapeData(_position, ENTITY_SHAPE_FIGHTER_SIZE, ENTITY_SHAPE_FIGHTER_PATH, IntRect(1, 0, 36, 33)), CT_CONSTRUCTION)
{
	data = new EntityData(10, 4, 1, .3f, 100, _level);
	brain = new EntityBrain(this);
	UpdateData();
	Init();
}

void Knight::Init()
{
	const float _speed = 0.1f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(1.0, 0.0f), Vector2f(36.0, 33.0f), READ_RIGHT, true, 2, _speed),
	AnimationData("Movement", Vector2f(0.0f, 36.0f), Vector2f(38.0, 34.0f), READ_RIGHT, true, 6, _speed),
	AnimationData("Attack", Vector2f(2.0f, 73.0f), Vector2f(40.0, 33.0f), READ_RIGHT, false, 2, _speed, "Idle"),
	AnimationData("Death", Vector2f(113.0f, 74.0f), Vector2f(40.0, 29.0f), READ_RIGHT, false, 1, _speed),
		});
}
