#pragma once
#include "EnemyBrain.h"
#include "MobAttackState.h"

class MobBrain : public EnemyBrain
{
	MobAttackState* attack;

public:
	AttackState* GetAttackState() const
	{
		return attack;
	}

public:
	MobBrain(Actor* _owner);

public:
	virtual void Init() override;
};