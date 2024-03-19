#pragma once
#include "State.h"
#include "InspectComponent.h"

class PatrolState : public State
{
	InspectComponent* inspect;

public:
	PatrolState(Brain* _brain);

public:
	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Stop() override;
};