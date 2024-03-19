#pragma once
#include "Actor.h"
#include "PlayerStat.h"
#include "Inventory.h"
#include "PlayerMovementComponent.h"
#include "PlayerAttackComponent.h"
#include "PlayerAnimationComponent.h"
#include "InteractionComponent.h"
#include "CollisionComponent.h"
#include "PlayerSoundData.h"

using namespace std;

class Player : public Actor
{
	PlayerStat* stats;
	Inventory* inventory;
	PlayerMovementComponent* movement;
	PlayerAttackComponent* attack;
	PlayerAnimationComponent* animation;
	InteractionComponent* interaction;
	SoundData* sound;
	PlayerSoundData data;

public:
	void SetStatus(const bool _status)
	{
		movement->SetCanMove(_status);
	}
	PlayerStat* GetStats() const
	{
		return stats;
	}
	Inventory* GetInventory() const
	{
		return inventory;
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