#pragma once
#include "AttackState.h"

class MobAttackState : public AttackState
{

public:
	MobAttackState(Brain* _brain);

public:
	virtual void Init() override;
	virtual void Start() override;
};