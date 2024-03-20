#pragma once
#include "InteractableActor.h"

enum BonusType
{
	Entity_AttackBonus,
	Entity_DefenseBonus,
	Entity_SpeedBonus,
	Construction_AttackBonus,
	Construction_DefenseBonus,
	Construction_SpeedBonus,
	Player_AttackBonus,
	Player_DefenseBonus,
	Player_SpeedBonus,
	None
};

struct BuildingData
{
	int healPointMax;
	int currentHP;
	int level;
	int cost;
	BonusType bonus;

	BuildingData(const int _hp,const int _cost ,const BonusType& _bonus)
	{
		level = 0;
		healPointMax = _hp + (_hp / 10 * level);
		currentHP = healPointMax;
		cost = _cost;
		bonus = _bonus;
	}
	void LevelUp()
	{
		level += 1;
		UpdateData();
	}
	void UpdateData()
	{
		healPointMax = healPointMax + (healPointMax / 10 * level);
	}
};

class Building : public InteractableActor
{
protected:
	BuildingData* data = nullptr;
	bool isDestroy = false;

public:
	Building(const string& _name, const ShapeData& _shape, Canvas* _canvas = nullptr);
	~Building();

	BuildingData* GetData() const
	{
		return data;
	}
	bool IsDestroy() const
	{
		return isDestroy;
	}
	virtual int GetCost() override
	{
		return data->cost;
	}
private:
	void TakeDamage(int _damage);
	void Repare();
};

