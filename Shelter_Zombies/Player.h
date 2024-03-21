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
#include "Building.h"
#include "InputManager.h"

using namespace std;

struct PlayerData
{
	string name;
	int healPointMax;
	int currentHP;
	int damagePoint;
	float speed;
	float range;
	int level;

	vector<Item*> equipments;
	vector<Spells*> spells;

	PlayerData(const string& _name,int _hp, int _dmg, float _speed, float _range, int _level)
	{
		name = _name;
		healPointMax = _hp + (_hp / 10 * _level);
		currentHP = healPointMax;
		damagePoint = _dmg + (_dmg / 10 * _level);
		speed = _speed;
		range = _range;
		level = _level;

		equipments = vector<Item*>();
		InitEquipments();
		spells = vector<Spells*>();
	}
	void InitEquipments()
	{
		equipments.push_back(new Item(3, new ItemWidget(ShapeData(Vector2f(), Vector2f(50.0f, 50.0f), "blue.png"), "Arme", ""),FONT,IT_WEAPON));
		equipments.push_back(new Item(5, new ItemWidget(ShapeData(Vector2f(), Vector2f(50.0f, 50.0f), "blue.png"), "Casque", ""),FONT,IT_HELMET));
		equipments.push_back(new Item(7, new ItemWidget(ShapeData(Vector2f(), Vector2f(50.0f, 50.0f), "blue.png"), "PLastron", ""),FONT,IT_CHESTPLATE));
		equipments.push_back(new Item(9, new ItemWidget(ShapeData(Vector2f(), Vector2f(50.0f, 50.0f), "blue.png"), "Bottes", ""),FONT,IT_BOOTS));
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
};

struct ConstructionMode
{
	InteractableActor* shapeOfConstruction;
	Vector2f position;
	int cost;

	ConstructionMode()
	{
		shapeOfConstruction = nullptr;
		position = Vector2f();
		cost = 0;
	}

	ConstructionMode(InteractableActor* _shape, const Vector2f& _position,const int _cost)
	{
		shapeOfConstruction = _shape;
		position = _position;
		cost = _cost;
	}

	void Reset()
	{
		shapeOfConstruction = nullptr;

		position = Vector2f();
		cost = 0;
	}
	void Destroy()
	{
		ActorManager::GetInstance().Remove(shapeOfConstruction);
		ActorManager::GetInstance().GarbageValues();
		shapeOfConstruction = nullptr;

		position = Vector2f();
		cost = 0;
	}
	
	void SetPosition(const Vector2f& _position)
	{
		position = _position;
		shapeOfConstruction->GetDrawable()->setPosition(_position);
	}
};

class Player : public Actor
{
	int gold;
	PlayerMovementComponent* movement;
	PlayerAttackComponent* attack;
	PlayerAnimationComponent* animation;
	PlayerData* data;

	ConstructionMode* mode;

public:
	int GetGold() const
	{
		return gold;
	}
	PlayerData* GetData() const
	{
		return data;
	}
	void SetStatus(const bool _status)
	{
		//movement->SetCanMove(_status);
	}
	PlayerMovementComponent* GetPlayerMovement()const
	{
		return movement;
	}
	void SetConstructionMode(InteractableActor* _building)
	{
		if (mode->shapeOfConstruction) return;

		mode->shapeOfConstruction = _building;
		mode->position = InputManager::GetInstance().GetMousePosition();
		mode->cost = _building->GetCost();
	}

public:
	Player(const string& _name, const ShapeData& _data);

private:
	void InitAnimations();
	void SetupPlayerInput();

public:
	virtual void Init() override;
	virtual void Update(const float _deltaTime) override;

	Vector2f MousePosition();
};