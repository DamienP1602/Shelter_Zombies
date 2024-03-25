#pragma once
#include "State.h"
#include "EntityMovementComponent.h"

class DeathState : public State
{
	EntityMovementComponent* movement = nullptr;

public:
	DeathState(Brain* _brain);

public:
	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Stop() override;
	virtual void Init() override;
};

