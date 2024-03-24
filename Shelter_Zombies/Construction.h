#pragma once
#include "InteractableActor.h"
#include "EntityLifeComponent.h"
#include "EntityAttackComponent.h"

class Entity;

struct ConstructionData
{
	int maxLife;
	int damagePoint;
	float cooldown;
	float range;
	int level;
	int cost;

	ConstructionData(const int _hp, const int _dmg, const float _cooldown, const float _range, const int _level,const int _cost)
	{
		maxLife = _hp;
		damagePoint = _dmg;
		cooldown = _cooldown;
		range = _range;
		level = _level;
		cost = _cost;
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
	EntityLifeComponent* life = nullptr;
	EntityAttackComponent* attack = nullptr;
	bool isDestroy = false;
	bool isActive = false;
	bool isAlly = false;

public:
	Construction(const string& _name, const ShapeData& _shape,const bool _isAlly = false, Canvas* _canvas = new Canvas("InteractableActor"));
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
	void SetActive(bool _value)
	{
		isActive = _value;
	}
	virtual bool IsAlly() const override
	{
		return isAlly;
	}

protected:
	virtual void Attack(Entity* _target);
	virtual void Register() override;
	void UpdateData();
};
