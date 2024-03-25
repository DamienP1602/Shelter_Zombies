#pragma once
#include "Component.h"
#include "Timer.h"
#include "Kismet.h"

class EntityAttackComponent : public Component
{
	int damages;
	float cooldown;
	float range;
	bool isInRange;
	HitInfo hitInfo;
	Timer* cooldownTimer;
	Actor* target = nullptr;

public:
	EntityAttackComponent(Actor* _owner);
	~EntityAttackComponent();

	void SetData(const int _damages, const float _cooldown, const float _range)
	{
		damages = _damages;
		cooldown = _cooldown;
		range = _range * 1.1f;
	}
	void SetTarget(Actor* _target)
	{
		target = _target;
	}
	void SetInRange(const bool _value)
	{
		isInRange = _value;
	}
	Actor* GetTarget() const
	{
		return target;
	}
	
	bool IsAttacking() const
	{
		return cooldownTimer && cooldownTimer->IsRunning();
	}
	bool IsTargetDead() const;
	bool IsInRange() const
	{
		return isInRange;
	}
	HitInfo GetHitInfo() const
	{
		return hitInfo;
	}

	virtual void Update(const float _deltaTime) override;
	void CheckTargetInRange();
	void Attack();
	void StartAttack();
	void StopAttack();
};