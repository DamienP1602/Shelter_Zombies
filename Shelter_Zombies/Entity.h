#pragma once
#include "Actor.h"
#include "EntityBrain.h"
#include "EntityMovementComponent.h"
#include "EntityAttackComponent.h"
#include "EntityLifeComponent.h"

struct EntityData
{
	int maxLife;
	int damagePoint;
	float cooldown;
	float speed;
	float range;
	int level;

	EntityData(int _hp, int _dmg, float _cooldown, float _speed, float _range, int _level)
	{
		maxLife = _hp;
		damagePoint = _dmg;
		cooldown = _cooldown;
		speed = _speed;
		range = _range;
		level = _level;
		UpdateData();
	}
	void LevelUp()
	{
		level += 1;
		UpdateData();
	}
	void UpdateData()
	{
		maxLife = maxLife + (maxLife / 10 * level);
		cooldown = cooldown - (0.2f * level);
		damagePoint = damagePoint + (damagePoint / 10 * level);
		speed = speed + (speed / 10 * level);
	}
};

/// <summary>
/// An entity in game.
/// </summary>
class Entity : public Actor
{
protected:
	Actor* target = nullptr;
	EntityData* data = nullptr;
	EntityBrain* brain = nullptr;
	EntityMovementComponent* movement = nullptr;
	EntityAttackComponent* attack = nullptr;
	EntityLifeComponent* life = nullptr;
	bool isActive = false;
	bool isAlly = true;

public:
	Entity(string _name, const bool _isAlly, const ShapeData& _shape, const CollisionType& _activeCollision);
	~Entity();

	void SetTarget(Actor* _target)
	{
		target = _target;
		attack->SetTarget(_target);
		movement->SetTarget(_target);
	}
	void SetActive(bool _value)
	{
		isActive = _value;
		movement->SetCanMove(_value);
	}
	Actor* GetTarget() const
	{
		return target;
	}
	EntityData* GetData() const
	{
		return data;
	}

	bool IsDead() const
	{
		return life->IsDead();
	}
	bool IsActive() const
	{
		return isActive;
	}
	/*virtual bool IsAlly() const override
	{
		return isAlly;
	}*/

protected:
	void UpdateData();
	virtual void Init() override;
};

