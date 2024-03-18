#pragma once
#include "EnemyBrain.h"
#include "BossAttackState.h"

class BossBrain : public EnemyBrain
{
	ChaseState* chase;
	BossAttackState* attack;

public:
	ChaseState* GetChaseState() const
	{
		return chase;
	}
	BossAttackState* GetAttackState() const
	{
		return attack;
	}

public:
	BossBrain(Actor* _owner);
	~BossBrain();

public:
	virtual void Init() override;
};