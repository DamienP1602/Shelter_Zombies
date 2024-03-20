#pragma once
#include "Enemy.h"
#include "MobMovementComponent.h"
#include "SightComponent.h"
#include "EntityAttackComponent.h"

class Player;

class Mob : public Enemy
{
protected:
	bool isPatrolling;
	bool cooldownAttack;

	MobMovementComponent* movement;
	SightComponent* sight;
	EntityAttackComponent* attack;

public:
	Mob(const ShapeData& _data);

public:
	virtual void Update(const float _deltaTime) override;
	virtual void Attack(Player* _player);
	virtual void Death();
};