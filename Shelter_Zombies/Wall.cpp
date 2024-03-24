#include "Wall.h"
#include "Macro.h"

#define CONSTRUCTION_SHAPE_WALL_PATH "Animations/Wall_sheet.png"
#define CONSTRUCTION_SHAPE_WALL_SIZE Vector2f(50, 50)

Wall::Wall(const Vector2f& _position, const int _level, const bool _isAlly) :
	Construction(STRING_ID("Wall"), ShapeData(_position, CONSTRUCTION_SHAPE_WALL_SIZE, CONSTRUCTION_SHAPE_WALL_PATH, IntRect(0, 0, 86, 84)), _isAlly)
{
	data = new ConstructionData(20, 0, 0, 0, _level, 3);
	UpdateData();
}

void Wall::Init()
{
	const float _speed = 1.f;

	animation->InitAnimations(
		{
			AnimationData("State_1", Vector2f(0.0, 0.0f), Vector2f(86.0, 84.0f), READ_DOWN, true, 1, _speed),
			AnimationData("State_2", Vector2f(0.0f, 84.0f), Vector2f(86.0, 84.0f), READ_DOWN, true, 1, _speed),
			AnimationData("State_3", Vector2f(0.0f, 168.0f), Vector2f(86.0, 84.0f), READ_DOWN, true, 1, _speed),
			AnimationData("State_4", Vector2f(0.0f, 252.0f), Vector2f(86.0, 84.0f), READ_DOWN, true, 1, _speed)
		});
}

void Wall::Update(const float _deltaTime)
{
	Actor::Update(_deltaTime);
	InteractableActor::Verify();

	if (life->GetLife() <= data->maxLife * 0.25f)
		animation->RunAnimation("State_4", 1);
	else if (life->GetLife() <= data->maxLife * 0.5f)
		animation->RunAnimation("State_3", 1);
	else if (life->GetLife() <= data->maxLife * 0.75f)
		animation->RunAnimation("State_2", 1);
	else
		animation->RunAnimation("State_1", 1);
}
