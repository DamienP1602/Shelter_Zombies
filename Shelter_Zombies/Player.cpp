#include "Player.h"
#include "Game.h"

// Sound
#include "SoundData.h"
// Mobs
#include "Mob.h"
#include "SoundData.h"
#include "SoundData.h"

// System
#include "Macro.h"
#include "Kismet.h"
#include "Camera.h"
// Managers
#include "ActorManager.h"
#include "InputManager.h"
#include"FxManager.h"
#include "Timer.h"
#include "TimerManager.h"
#include "PlayerSound.h"
#include "MusicData.h"
#include "MenuManager.h"
#include "GameMenu.h"
#include "CameraManager.h"


Player::Player(const string& _name, const ShapeData& _data) : Actor(_name, _data, CT_BLOCK)
{
	animation = new PlayerAnimationComponent(this);
	components.push_back(animation);

	movement = new PlayerMovementComponent(this);
	components.push_back(movement);

	attack = new PlayerAttackComponent(this, 1);
	components.push_back(attack);

	mode = new ConstructionMode();
	data = new PlayerData(15,4,5,2,1);

	Init();
}


void Player::InitAnimations()
{
	//animation->Init();
}

void Player::SetupPlayerInput()
{
	new ActionMap("Controler", {
		ActionData("Right",[&]() { movement->SetDirectionX(1.0f,"Right"); },InputData({ActionType::KeyPressed, Keyboard::D})),
		ActionData("StopRight", [&]() { movement->SetDirectionX(0.0f, "StopRight"); }, InputData({ ActionType::KeyReleased, Keyboard::D })),

		ActionData("Up",[&]() { movement->SetDirectionY(-1.0f); },InputData({ActionType::KeyPressed, Keyboard::Z})),
		ActionData("StopUp", [&]() { movement->SetDirectionY(0.0f); }, InputData({ ActionType::KeyReleased, Keyboard::Z })),

		ActionData("Down",[&]() { movement->SetDirectionY(1.0f); },InputData({ActionType::KeyPressed, Keyboard::S})),
		ActionData("StopDown", [&]() { movement->SetDirectionY(0.0f); }, InputData({ ActionType::KeyReleased, Keyboard::S })),

		ActionData("Left",[&]() { movement->SetDirectionX(-1.0f,"Left"); },InputData({ActionType::KeyPressed, Keyboard::Q})),
		ActionData("StopLeft", [&]() { movement->SetDirectionX(0.0f, "StopLeft"); }, InputData({ ActionType::KeyReleased, Keyboard::Q })),
		});

	new ActionMap("GlobalInputs", {
		ActionData("OpenMenu",[&]()
			{
				if (MenuManager::GetInstance().Get("GameMenu"))
				{
					MenuManager::GetInstance().SetCurrent("GameMenu");
					MenuManager::GetInstance().DisableNotCurrent();
				}
				else
				{
					new GameMenu();
				}				
			},InputData({ActionType::KeyPressed, Keyboard::Escape})),
		});

}

void Player::TryToOpen(Menu* _menu, const bool _restoreActions)
{
	const bool _isActive = _menu->IsActive();
	CloseAllMenus(_restoreActions);

	if (!_isActive)
	{
		SoundManager::GetInstance().Stop("bench rest");
		new SoundData("bossgushing", 50.0f, false);

		movement->SetCanMove(false);
		attack->SetCanAttack(false);
		_menu->SetStatus(true);
		//stats->SetStatus(false);
	}

	else
	{
		SoundManager::GetInstance().Stop("bossgushing");
		new SoundData("bench rest", 50.0f, false);
	}
}

void Player::CloseAllMenus(const bool _restoreActions)
{
	/*stats->SetStatus(true);
	inventory->SetStatus(false);
	interaction->StopInteract();*/

	if (_restoreActions)
	{
		movement->SetCanMove(true);
		attack->SetCanAttack(true);
	}
}

void Player::Init()
{
	movement->SetCanMove(true);
	/*stats->SetStatus(true);
	inventory->SetStatus(false);*/

	InitAnimations();
	SetupPlayerInput();
}

void Player::Update(const float _deltaTime)
{
	Actor::Update(_deltaTime);

	if (mode->shapeOfConstruction)
	{
		const Vector2f& _mousePosition = Vector2f(Mouse::getPosition(Game::GetWindow()));
		const Vector2f& _playerPosition = Game::GetPlayer()->GetShapePosition();
		const Vector2f& _windowSize = Game::GetWindowSize();
		mode->SetPosition((_mousePosition + _playerPosition) - _windowSize / 2.0f);
	}
}