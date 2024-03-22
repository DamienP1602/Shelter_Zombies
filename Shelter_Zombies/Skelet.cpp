#include "Skelet.h"
#include "EntityBrain.h"
#include "EnemyEntityManager.h"
#include "ActorManager.h"
#include "io.h"

#define ENTITY_SHAPE_FIGHTER_PATH "Animations/Skelet_sheet.png"
#define ENTITY_SHAPE_FIGHTER_SIZE Vector2f(75.f,75.f)

Skelet::Skelet(const Vector2f& _position, const int _level) :
	Entity(STRING_ID("Skelet"), false, ShapeData(_position, ENTITY_SHAPE_FIGHTER_SIZE, ENTITY_SHAPE_FIGHTER_PATH, IntRect(0, 0, 43, 37)), CT_CONSTRUCTION)
{
	data = new EntityData(10, 4, 1, .3f, 100, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

void Skelet::Init()
{
	const float _speed = 0.1f;

	animation->InitAnimations(
	{
		AnimationData("Idle", Vector2f(0.0, 0.0f), Vector2f(43.0, 37.0f), READ_RIGHT, true, 4, _speed),
		AnimationData("Movement", Vector2f(0.0f, 42.0f), Vector2f(36.0, 33.0f), READ_RIGHT, true, 8, _speed),
		AnimationData("Attack", Vector2f(0.0f, 77.0f), Vector2f(45.0, 53.0f), READ_RIGHT, false, 5, _speed, "Idle"),
		AnimationData("Death", Vector2f(2.0f, 133.0f), Vector2f(32.0, 20.0f), READ_RIGHT, false, 2, _speed)
	});
}
