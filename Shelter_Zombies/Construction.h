#pragma once
#include "InteractableActor.h"

class Entity;

struct ConstructionData
{
	int healPointMax;
	int currentHP;
	int damagePoint;
	int level;
	int cost;

	ConstructionData(const int _hp, const int _dmg, const int _level,const int _cost)
	{
		healPointMax = _hp + (_hp / 10 * _level);
		currentHP = healPointMax;
		damagePoint = _dmg + (_dmg / 10 * _level);
		level = _level;
		cost = _cost;
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
	}
};

/// <summary>
/// A destructible construction on map
/// </summary>
class Construction : public InteractableActor
{
protected:
	ConstructionData* data;
	bool isDestroy;

public:
	Construction(const string& _name, const ShapeData& _shape, Canvas* _canvas = new Canvas("InteractableActor"));
	~Construction();

	ConstructionData* GetData() const
	{
		return data;
	}
	virtual int GetCost() override
	{
		return data->cost;
	}
	bool IsDestroy() const
	{
		return isDestroy;
	}

private:
	void TakeDamage(int _damage);
	void Repare();
	void Attack(Entity* _target);
};
