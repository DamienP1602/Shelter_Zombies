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
#include "Gameplay.h"

Player::Player(const string& _name, const ShapeData& _data) : Actor(_name, _data, CT_ENTITY)
{
	movement = new PlayerMovementComponent(this);
	components.push_back(movement);

	mode = new ConstructionMode();
	data = new PlayerData(_name, 150, 5, 5, 3, 1); //TODO remove change test 

	attack = new PlayerAttackComponent(this, data->damagePoint, data->range);
	components.push_back(attack);

	life = new EntityLifeComponent(this);
	components.push_back(life);

	gold = 1500;

	Init();
}


void Player::InitAnimations()
{
	const Vector2f& _size = Vector2f(120.0f, 80.0f);
	const float _speed = 0.1f;

	animation->InitAnimations({
		AnimationData("Idle", Vector2f(0.0f, 80.0f), _size, READ_RIGHT, true, 10, _speed),
		AnimationData("RunRight", Vector2f(0.0f, 160.0f), _size, READ_RIGHT, true, 10, _speed),
		AnimationData("RunLeft", Vector2f(0.0f, 160.0f), _size, READ_RIGHT, true, 10, _speed),
		AnimationData("Death", Vector2f(0.0f, 0.0f), _size, READ_RIGHT, true, 10, _speed),
		AnimationData("Attack", Vector2f(0.0f, 240.0f), _size, READ_RIGHT, false, 4, _speed,"Idle")
		});

	movement->SetAnimationComponent(animation);
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
					if (Gameplay::GetInstance().GetCurrentMap()->PutInMap(mode->shapeOfConstruction, MousePosition()))
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

bool Player::UpgradeEquipment(const int _index)
{
	return data->equipments[_index]->TryToUpgrade(this);
}

void Player::Init()
{
	//movement->SetCanMove(true);
	/*stats->SetStatus(true);
	inventory->SetStatus(false);*/

	attack->SetData(data->damagePoint, data->cooldown, data->range);
	life->SetLife(data->maxLife);
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
