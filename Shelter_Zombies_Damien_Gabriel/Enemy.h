#pragma once
#include "Actor.h"
#include "EntityLifeComponent.h"
#include "EntityBrain.h"

enum EnemyType
{
	BOSS, 
	MOB
};

enum MobType
{
	MOB1,
	MOB2
};

enum BossType
{
	FALSE_KNIGHT
};

class Enemy : public Actor
{
protected:
	bool isDead;
	EntityBrain* brain;
	EntityLifeComponent* life;

public:
	Enemy(const string& _name, const ShapeData& _data);

public:
	EntityBrain* GetBrain() const
	{
		return brain;
	}
	EntityLifeComponent* GetLife() const
	{
		return life;
	}
	bool IsDead() const
	{
		return isDead;
	}

public:
	virtual void Update(const float _deltaTime);
};

