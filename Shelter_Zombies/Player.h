#pragma once
#include "Actor.h"
#include "PlayerMovementComponent.h"
#include "PlayerAttackComponent.h"
#include "PlayerAnimationComponent.h"
#include "CollisionComponent.h"
#include "Menu.h"
#include "Entity.h"
#include "Spells.h"
#include "Macro.h"
#include "Item.h"

using namespace std;

struct PlayerData
{
	int healPointMax;
	int currentHP;
	int damagePoint;
	float speed;
	float range;
	int level;

	vector<Item*> equipments;
	vector<Spells*> spells;

	PlayerData(int _hp, int _dmg, float _speed, float _range, int _level)
	{
		healPointMax = _hp + (_hp / 10 * _level);
		currentHP = healPointMax;
		damagePoint = _dmg + (_dmg / 10 * _level);
		speed = _speed;
		range = _range;
		level = _level;

		equipments = vector<Item*>(4);
		spells = vector<Spells*>(3);
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
	void AddSpells(Spells* _spell)
	{
		if (SIZE(spells) == 3) return;

		spells.push_back(_spell);
	}
	void SetEquipment()
	{
		equipments.push_back(new Item(new ItemWidget(ShapeData(Vector2f(),Vector2f(50.0f,50.0f)),"titlte","text"),FONT));
	}
};

class Player : public Actor
{
	int gold;
	PlayerMovementComponent* movement;
	PlayerAttackComponent* attack;
	PlayerAnimationComponent* animation;
	EntityData* data;

public:
	void SetStatus(const bool _status)
	{
		//movement->SetCanMove(_status);
	}
	PlayerMovementComponent* GetPlayerMovement()const
	{
		return movement;
	}

public:
	Player(const string& _name, const ShapeData& _data);

private:
	void InitAnimations();
	void SetupPlayerInput();
	void TryToOpen(Menu* _menu, const bool _restoreActions = true);

public:
	virtual void Init() override;
	virtual void Update(const float _deltaTime) override;
	void CloseAllMenus(const bool _restoreActions);
};