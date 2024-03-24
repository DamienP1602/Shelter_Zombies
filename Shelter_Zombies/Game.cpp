#include "Game.h"
#include "TimerManager.h"
#include "InputManager.h"
#include "ActorManager.h"
#include "HUD.h"
#include "Widget.h"
#include "TriggerBox.h"
#include "Gameplay.h"
#include "TriggerBox.h"

#include "VillageMenu.h"
#include "AttackMenu.h"
#include "InventoryPlayer.h"
#include "BuildingMenu.h"
#include "BarrakMenu.h"
#include "GameMenu.h"
#include "MultiMapMenu.h"

#define PLAYER_PATH "Entities/Player/_Player.png"

RenderWindow Game::window;
Player* Game::player;
Camera* Game::camera;

Game::Game()
{
	player = new Player("Player", ShapeData(Vector2f(500.0f, 500.0f), Vector2f(75.0f, 75.0f), PLAYER_PATH));
	camera = new Camera();
}

Game::~Game()
{
	player = nullptr;
	camera = nullptr;
	map = nullptr;
	delete map;
	delete player;
	delete camera;
}

void Game::Start()
{
	window.create(VideoMode(1920, 1080), "Shelter Game"/*, Style::Fullscreen*/);

	TimerManager::GetInstance().SetRenderCallback(bind(&Game::UpdateWindow, this));
	Init();
	Update();
}

void Game::Init()
{
	Gameplay::GetInstance().AddMap(new Map("0"));

	Gameplay::GetInstance().AddMap(new Map("1"));
	Gameplay::GetInstance().AddMap(new Map("2"));
	Gameplay::GetInstance().Init(this);
	camera->Init();

	InitPlayerMap();
	new VillageMenu();
}

void Game::InitPlayerMap()
{
	AllyBuildingManager::GetInstance().SetNexus(Vector2f(15.0f, 15.0f));
		
}

void Game::Update()
{
	while (window.isOpen())
	{
		TimerManager::GetInstance().Update();
		Gameplay::GetInstance().Update();
		if (!InputManager::GetInstance().Update(window))
			break;
		ActorManager::GetInstance().Update();
	}
}

void Game::UpdateWindow()
{
	window.clear();

	const float _deltaTime = TimerManager::GetInstance().GetDeltaTime();
	camera->Update(_deltaTime);
	window.setView(camera->GetView());

	DrawMap();
	DrawActors();
	DrawUIs();

	window.display();
}

#pragma region Draws

void Game::DrawMap()
{
	for (ShapeObject* _drawable : Gameplay::GetInstance().GetCurrentMap()->GetAllDrawables())
	{
		if (_drawable->IsHidden() || !_drawable)
			continue;
		window.draw(*_drawable->GetDrawable());
	}
}

void Game::DrawActors()
{
	for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	{
		if (_actor->IsHidden() || _actor->IsToRemove())
			continue;
		window.draw(*_actor->GetDrawable());
	}
}

void Game::DrawUIs()
{
	View _view = window.getDefaultView();
	for (Canvas* _canvas : HUD::GetInstance().GetAllValues())
	{
		if (!_canvas->IsVisible())
			continue;
		_view.setViewport(_canvas->GetRect());
		window.setView(_view);

		for (Widget* _widget : _canvas->GetUiWidgets())
		{
			if (!_widget->IsVisible() || !_widget)
				continue;
			window.draw(*_widget->GetDrawable());
		}
	}
}
#pragma endregion

void Game::Stop()
{
	cout << "A bientot !" << endl;
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}

void Game::Close()
{
	window.close();
}