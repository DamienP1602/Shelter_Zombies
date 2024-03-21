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
	EntityAttackComponent(Actor* _owner, const int _damages, const int _cooldown, const int _range);
	~EntityAttackComponent();

	void SetData(const int _damages, const float _cooldown, const float _range)
	{
		damages = _damages;
		cooldown = _cooldown;
		range = _range;
	}
	void SetTarget(Actor* _target)
	{
		target = _target;
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
	HitInfo GetHitInfo() const
	{
		return hitInfo;
	}
	void SetInRange(const bool _value)
	{
		isInRange = _value;
	}

	virtual void Update(const float _deltaTime) override;
	void CheckTargetInRange();
	void Attack();
	void StartAttack();
	void StopAttack();
};