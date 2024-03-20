#include "Boss.h"
#include "Macro.h"
#include "BossBrain.h"

Boss::Boss(const ShapeData& _data) : Enemy("Boss" + to_string(GetUniqueID()), _data)
{
	life = new EntityLifeComponent(this, 3);
	components.push_back(life);

	movement = new MobMovementComponent(this);
	movement->SetSpeed(0.5f);
	components.push_back(movement);

	movement->SetSpeed(0.5f);

	sight = new SightComponent(this, 500.0f);
	components.push_back(sight);

	attack = new EntityAttackComponent(this, 1, 5, 2);
	components.push_back(attack);

	brain = new BossBrain(this);
	components.push_back(brain);
}

void Boss::Update(const float _deltaTime)
{
	Enemy::Update(_deltaTime);
}