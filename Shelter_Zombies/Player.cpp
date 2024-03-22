#include "Player.h"
#include "Game.h"

// Sound
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
#include "VillageMenu.h"



Player::Player(const string& _name, const ShapeData& _data) : Actor(_name, _data, CT_BLOCK)
{
	animation = new PlayerAnimationComponent(this);
	components.push_back(animation);

	movement = new PlayerMovementComponent(this);
	components.push_back(movement);

	mode = new ConstructionMode();
	data = new PlayerData(_name,15,4,5,3,1);

	attack = new PlayerAttackComponent(this, data->damagePoint,data->range);
	components.push_back(attack);
	
	gold = 1500;

	Init();
}


void Player::InitAnimations()
{
	animation->Init();
}

void Player::SetupPlayerInput()
{
	new ActionMap("Controler", {
		ActionData("Right",[&]() { movement->SetDirectionX(1.0f,"RunRight"); },InputData({ActionType::KeyPressed, Keyboard::D})),
		ActionData("StopRight", [&]() { movement->SetDirectionX(0.0f, "Idle"); }, InputData({ActionType::KeyReleased, Keyboard::D})),

		ActionData("Up",[&]() { movement->SetDirectionY(-1.0f); },InputData({ActionType::KeyPressed, Keyboard::Z})),
		ActionData("StopUp", [&]() { movement->SetDirectionY(0.0f); }, InputData({ ActionType::KeyReleased, Keyboard::Z })),

		ActionData("Down",[&]() { movement->SetDirectionY(1.0f); },InputData({ActionType::KeyPressed, Keyboard::S})),
		ActionData("StopDown", [&]() { movement->SetDirectionY(0.0f); }, InputData({ ActionType::KeyReleased, Keyboard::S })),
		
		ActionData("Left",[&]() { movement->SetDirectionX(-1.0f,"RunLeft"); },InputData({ActionType::KeyPressed, Keyboard::Q})),
		ActionData("StopLeft", [&]() { movement->SetDirectionX(0.0f, "Idle"); }, InputData({ActionType::KeyReleased, Keyboard::Q})),
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

		ActionData("Create",[&]()
			{
				if (mode->shapeOfConstruction)
				{
					if (Game::GetMap()->PutInMap(mode->shapeOfConstruction, MousePosition()))
					{
						mode->Reset();
					}
				}
			},InputData({ActionType::MouseButtonPressed, Mouse::Left})),
		ActionData("UndoCreate",[&]() 
			{ 
				if (mode->shapeOfConstruction)
				{
					mode->Destroy();
				}
			}
			,InputData({ActionType::MouseButtonPressed, Mouse::Right})),
		});


}

Vector2f Player::MousePosition()
{
	const Vector2f& _mousePosition = Vector2f(Mouse::getPosition(Game::GetWindow()));
	const Vector2f& _playerPosition = Game::GetPlayer()->GetShapePosition();
	const Vector2f& _windowSize = Game::GetWindowSize();

	return (_mousePosition + _playerPosition) - _windowSize / 2.0f;
}

void Player::UpgradeEquipment(const int _index)
{
	data->equipments[_index]->TryToUpgrade(this);
}

void Player::Init()
{
	//movement->SetCanMove(true);
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
		mode->SetPosition(MousePosition());
	}
}

void PlayerData::CheckHealthAmelioration()
{
	if (GetActualHealth() != GetMaximumHealth())
	{
		currentHP = GetMaximumHealth();
		MenuManager::GetInstance().GetSpecificValues<VillageMenu>()[0]->InitTexts();
	}
}
