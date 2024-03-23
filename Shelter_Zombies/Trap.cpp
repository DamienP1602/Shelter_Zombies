#include "Trap.h"

#define CONSTRUCTION_SHAPE_TRAP_PATH "GPE/Construction/Trap_1.png"
#define CONSTRUCTION_SHAPE_TRAP_SIZE Vector2f(50,50)

Trap::Trap(const Vector2f& _position) :
	Construction("Trap", ShapeData(_position, CONSTRUCTION_SHAPE_TRAP_SIZE, CONSTRUCTION_SHAPE_TRAP_PATH))
{
	data = new ConstructionData(10, 10, 10, 0, 0,20);
	UpdateData();
}

void Trap::Init()
{
	//const float _speed = 1.f;

	//animation->InitAnimations(
	//	{
	//		AnimationData("Idle", Vector2f(0.0, 0.0f), Vector2f(86.0, 84.0f), READ_DOWN, true, 1, _speed),
	//		AnimationData("Attack", Vector2f(0.0f, 84.0f), Vector2f(86.0, 84.0f), READ_DOWN, true, 1, _speed),
	//		AnimationData("Death", Vector2f(0.0f, 168.0f), Vector2f(86.0, 84.0f), READ_DOWN, true, 1, _speed),
	//	});
}
