#pragma once
#include "Component.h"
#include "PlayerAnimationComponent.h"
#include "EntityAttackComponent.h"

using namespace std;

class PlayerAttackComponent : public EntityAttackComponent
{
	PlayerAnimationComponent* animation;

public:
	PlayerAttackComponent(Actor* _owner,const int _damages, const float _range);
	~PlayerAttackComponent();

public:
	virtual void Update(const float _deltaTime) override;
};

