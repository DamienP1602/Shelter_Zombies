#pragma once
#include"Component.h"

class EntityLifeComponent : public Component
{
	int maxLife;
	int currentLife;
	bool isDead;

public:
	EntityLifeComponent(Actor* _owner);

	void SetLife(const int _life)
	{
		maxLife = _life;
		currentLife = maxLife;
	}
	void RestoreLife()
	{
		currentLife = maxLife;
	}

	int GetLife() const
	{
		return currentLife;
	}
	bool IsDead() const
	{
		return isDead;
	}

	void TakeDamages(const int _damages);
	void Healing(const int _heal);

private:
	void Destroy();
};