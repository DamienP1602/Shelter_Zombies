#pragma once
#include "Brain.h"
#include "StandbyState.h"
#include "AttackState.h"
#include "ChaseState.h"
#include "DeathState.h"

class EntityBrain : public Brain
{
public:
	ChaseState* chase;
	AttackState* attack;
	StandbyState* standby;
	DeathState* death;

public:
	StandbyState* GetStanbyState() const
	{
		return standby;
	}
	ChaseState* GetChaseState() const
	{
		return chase;
	}
	AttackState* GetAttackState() const
	{
		return attack;
	}
	DeathState* GetDeathState() const
	{
		return death;
	}

public:
	EntityBrain(Actor* _owner);
	~EntityBrain();

public:
	void Init() override;
};