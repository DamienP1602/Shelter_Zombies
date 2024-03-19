#pragma once
#include "Actor.h"

struct EntityData
{
	int healPointMax;
	int currentHP;
	int damagePoint;
	float speed;
	float range;
	int level;

	EntityData(int _hp, int _dmg, float _speed, float _range, int _level)
	{
		healPointMax = _hp + (_hp / 10 * _level);
		currentHP = healPointMax;
		damagePoint = _dmg + (_dmg / 10 * _level);
		speed = _speed;
		range = _range;
		level = _level;
	}
	void LevelUp()
	{
		level += 1;
		UpdateData();
	}
	void UpdateData()
	{
		healPointMax = healPointMax + (healPointMax / 10 * level);
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
	Entity* target = nullptr;
	EntityData* data = nullptr;
	bool isDead = false;
	bool isActive = false;

public:
	Entity(string _name, const ShapeData& _shape);
	~Entity();

	Entity* GetTarget() const
	{
		return target;
	}
	void SetTarget(Entity* _target)
	{
		target = _target;
	}
	EntityData* GetData() const
	{
		return data;
	}
	bool IsDead() const
	{
		return isDead;
	}
	bool IsActive() const
	{
		return isActive;
	}
	void SetActive(bool _value)
	{
		isActive = _value;
	}

	void TakeDamage(int _damage);
	void Healing(int _heal);

protected:
	virtual void Movement() = 0;
	virtual void Action();
};

