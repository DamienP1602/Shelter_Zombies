#pragma once
#include "State.h"
#include "ChaseToAttack.h"
#include "ChaseToDeath.h"
#include "EntityMovementComponent.h"

class ChaseState : public State
{
	ChaseToAttack* chaseToAttack;
	ChaseToDeath* chaseToDeath;
	EntityMovementComponent* movement = nullptr;

private:
	Timer* chaseTimer;
	Timer* stopChaseTimer;

public:
	ChaseState(Brain* _brain);
	~ChaseState();

public:
	virtual void Init() override;
	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Stop() override;
};