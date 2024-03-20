#pragma once
#include "State.h"
#include "AttackToStandby.h"
#include "AttackToChase.h"
#include "EntityAttackComponent.h"

class AttackState : public State
{
	AttackToStandby* attackToStandby = nullptr;
	AttackToChase* attackToChase = nullptr;
	EntityAttackComponent* attack = nullptr;

public:
	AttackState(Brain* _brain);
	~AttackState();

public:
	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Stop() override;
	void Init() override;
};