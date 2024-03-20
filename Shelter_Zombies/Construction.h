#pragma once
#include "InteractableActor.h"

class Entity;

struct ConstructionData
{
	int maxLife;
	int currentLife;
	int damagePoint;
	int level;

	ConstructionData(int _hp, int _dmg, int _level)
	{
		maxLife = _hp + (_hp / 10 * _level);
		currentLife = maxLife;
		damagePoint = _dmg + (_dmg / 10 * _level);
		level = _level;
	}
	void LevelUp()
	{
		level += 1;
		UpdateData();
	}
	void UpdateData()
	{
		maxLife = maxLife + (maxLife / 10 * level);
		damagePoint = damagePoint + (damagePoint / 10 * level);
	}
};

/// <summary>
/// A destructible construction on map
/// </summary>
class Construction : public InteractableActor
{
protected:
	ConstructionData* data = nullptr;
	bool isDestroy = false;
	bool isActive = false;

public:
	Construction(const string& _name, const ShapeData& _shape, Canvas* _canvas = nullptr);
	~Construction();

	void RestoreLife() const
	{
		data->currentLife = data->maxLife;
	}

	ConstructionData* GetData() const
	{
		return data;
	}
	bool IsDestroy() const
	{
		return isDestroy;
	}
	void SetActive(bool _value)
	{
		isActive = _value;
	}

private:
	void TakeDamage(int _damage);
	void Repare();
	void Attack(Entity* _target);
};
