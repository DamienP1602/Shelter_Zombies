#include "Turret.h"

#define CONSTRUCTION_SHAPE_TURRET_PATH "Animations/Canon_sheet.png"
#define CONSTRUCTION_SHAPE_TURRET_SIZE Vector2f(50,50)

Turret::Turret(const Vector2f& _position) :
	Construction("Turret", ShapeData(_position, CONSTRUCTION_SHAPE_TURRET_SIZE, CONSTRUCTION_SHAPE_TURRET_PATH, IntRect(0, 0, 54, 50)))
{
	data = new ConstructionData(6, 3, 2, 500, 0, 30);
	UpdateData();
}

void Turret::Init()
{
	const float _speed = 1.f;

	animation->InitAnimations(
		{
			AnimationData("Idle", Vector2f(4.0, 0.0f), Vector2f(54.0, 50.0f), READ_DOWN, true, 1, _speed),
			AnimationData("Attack", Vector2f(6.0f, 54.0f), Vector2f(62.0, 48.0f), READ_DOWN, true, 1, _speed),
			AnimationData("Death", Vector2f(122.0f, 0.0f), Vector2f(54.0, 50.0f), READ_DOWN, true, 1, _speed)
		});
}
