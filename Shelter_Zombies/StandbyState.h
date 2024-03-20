#pragma once
#include "State.h"
#include "StandbyToChase.h"
#include "StandbyToDeath.h"

class Entity;

class StandbyState : public State
{
	Entity* entity = nullptr;
	StandbyToChase* standbyToChase = nullptr;
	StandbyToDeath* standbyToDeath = nullptr;

public:
	StandbyState(Brain* _brain);
	~StandbyState();

public:
	virtual void Init() override;
	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Stop() override;
};