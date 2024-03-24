#pragma once
#include "Actor.h"
#include "PlayerMovementComponent.h"
#include "PlayerAttackComponent.h"
#include "PlayerAnimationComponent.h"
#include "EntityLifeComponent.h"
#include "CollisionComponent.h"
#include "Menu.h"
#include "Entity.h"
#include "Spells.h"
#include "Macro.h"
#include "Item.h"
#include "Building.h"
#include "InputManager.h"

using namespace std;

struct PlayerData : public EntityData
{
	string name;

	vector<Item*> equipments;
	vector<Spells*> spells;

	PlayerData(const string& _name, int _hp, int _dmg, float _speed, float _range, int _level) : EntityData(_hp, _dmg, 1, _speed, _range, _level)
	{
		name = _name;
		equipments = vector<Item*>();
		InitEquipments();
		spells = vector<Spells*>();
	}
	void InitEquipments()
	{
		equipments.push_back(new Item(10, 2, 1, 0, new ItemWidget(ShapeData(Vector2f(), Vector2f(50.0f, 50.0f), "blue.png"), "Arme", ""), FONT, IT_WEAPON));
		equipments.push_back(new Item(7, 1, 1, 0, new ItemWidget(ShapeData(Vector2f(), Vector2f(50.0f, 50.0f), "blue.png"), "Casque", ""), FONT, IT_HELMET));
		equipments.push_back(new Item(12, 3, 1, 0, new ItemWidget(ShapeData(Vector2f(), Vector2f(50.0f, 50.0f), "blue.png"), "PLastron", ""), FONT, IT_CHESTPLATE));
		equipments.push_back(new Item(5, 0.25f, 1, 0, new ItemWidget(ShapeData(Vector2f(), Vector2f(50.0f, 50.0f), "blue.png"), "Bottes", ""), FONT, IT_BOOTS));
	}

	void AddSpells(Spells* _spell)
	{
		if (SIZE(spells) == 3) return;

		spells.push_back(_spell);
	}
	template <typename T>
	void Upgrade(const int _index, const T& _value)
	{
		if (_index <= 1) damagePoint += _value;
		if (_index == 2)
		{
			maxLife += _value;
			//currentHP = maxLife;
		}
		if (_index == 3) speed += _value;
	}
	int GetDamage() const
	{
		return damagePoint;
	}
	int GetMaximumHealth() const
	{
		return maxLife;
	}
	float GetSpeed() const
	{
		return speed;
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

	ConstructionMode(InteractableActor* _shape, const Vector2f& _position, const int _cost)
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
	EntityLifeComponent* life;
	PlayerAnimationComponent* animation;
	PlayerData* data;

	ConstructionMode* mode;

public:
	int GetGold() const
	{
		return gold;
	}
	void AddGold(const int _gold)
	{
		gold += _gold;
	}
	void RemoveGold(const int _gold)
	{
		gold -= _gold;
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
	bool UpgradeEquipment(const int _index);
	virtual void Init() override;
	virtual void Update(const float _deltaTime) override;

	Vector2f MousePosition();
};