#include "Golem.h"
#include "EntityBrain.h"
#include "EnemyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_ARTILLERY_PATH "Animations/Golem_sheet.png"
#define ENTITY_SHAPE_ARTILLERY_SIZE Vector2f(75.f,75.f)

Golem::Golem(const Vector2f& _position, const int _level) :
	Entity(STRING_ID("Golem"), false, ShapeData(_position, ENTITY_SHAPE_ARTILLERY_SIZE, ENTITY_SHAPE_ARTILLERY_PATH, IntRect(4, 2, 17, 32)), CT_CONSTRUCTION)
{
	data = new EntityData(3, 8, 6, .1f, 600, _level);
	brain = new EntityBrain(this);
	UpdateData();
	Init();
}

void Golem::Init()
{
	const float _speed = 0.1f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(0.0, 2.0f), Vector2f(22.0, 32.0f), READ_RIGHT, true, 1, _speed),
	AnimationData("Movement", Vector2f(0.0f, 2.0f), Vector2f(22.0, 32.0f), READ_RIGHT, true, 5, _speed),
	AnimationData("Attack", Vector2f(1.0f, 35.0f), Vector2f(32.0, 33.0f), READ_RIGHT, false, 3, _speed, "Idle"),
	AnimationData("Death", Vector2f(1.0f, 69.0f), Vector2f(31.0, 33.0f), READ_RIGHT, false, 3, _speed),
		});
}
