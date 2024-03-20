#pragma once
#include "Enemy.h"
#include "MobMovementComponent.h"
#include "EntityAttackComponent.h"
#include "SightComponent.h"
#include "Game.h"

class Boss : public Enemy
{
protected:
	MobMovementComponent* movement;
	EntityAttackComponent* attack;
	SightComponent* sight;

public:
	Boss(const ShapeData& _data);

public:
	virtual void Update(const float _deltaTime) override;
};