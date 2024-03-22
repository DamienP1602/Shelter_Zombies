#include "Priest.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SUPPORT_PATH "Animations/Priest_sheet.png"
#define ENTITY_SHAPE_SUPPORT_SIZE Vector2f(75.f,75.f)

Priest::Priest(const Vector2f& _position, const int _level) :
	Entity("Church", true, ShapeData(_position, ENTITY_SHAPE_SUPPORT_SIZE, ENTITY_SHAPE_SUPPORT_PATH, IntRect(4, 3, 35, 49)), CT_CONSTRUCTION)
{
	data = new EntityData(6, -3, 4, .8f, 300, _level);
	brain = new EntityBrain(this);
	UpdateData();
	Init();
}

void Priest::Init()
{
	const float _speed = 0.1f;

	animation->InitAnimations({
	AnimationData("Idle", Vector2f(4.0, 3.0f), Vector2f(35.0, 49.0f), READ_RIGHT, true, 2, _speed),
	AnimationData("Movement", Vector2f(3.0f, 58.0f), Vector2f(33.0, 49.0f), READ_RIGHT, true, 4, _speed),
	AnimationData("Attack", Vector2f(0.0f, 112.0f), Vector2f(47.0, 49.0f), READ_RIGHT, false, 2, _speed, "Idle"),
	AnimationData("Death", Vector2f(2.0f, 167.0f), Vector2f(51.0, 30.0f), READ_RIGHT, false, 1, _speed),
		});
}
