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

//TODO GAME change anim player's path
//#define PATH_PLAYER "Animations/knighModif.png"

RenderWindow Game::window;
Map* Game::map;
Player* Game::player;
Camera* Game::camera;

Game::Game()
{
	player = new Player("Player", ShapeData(Vector2f(500.0f, 500.0f), Vector2f(75.0f, 75.0f)));
	map = new Map();
	camera = new Camera();
} 

Game::~Game()
{
	delete map;
}


void Game::Start()
{
	window.create(VideoMode(1920, 1080), "Shelter Game", Style::Fullscreen);

	TimerManager::GetInstance().SetRenderCallback(bind(&Game::UpdateWindow, this));
	Init();
	Update();
}

void Game::Init()
{
	map->Init();
	camera->Init();
	Gameplay::GetInstance().Init(this);

	//new InventoryPlayer();
	new VillageMenu();
	//new AttackMenu();
	//new BuildingMenu();
	//new BarrackMenu();
	//GameMenu();

	/*TriggerBox* _box = new TriggerBox(ShapeData(Vector2f(100.0f, 0.0f), Vector2f(200.0f, 200.0f), ""), [&]() {
		cout << "coucou" << endl;
	});
	_box->GetComponent<CollisionComponent>()->GetBoxCollision()->GetDrawable()->setOutlineThickness(-5.0f);
	_box->GetComponent<CollisionComponent>()->GetBoxCollision()->GetDrawable()->setFillColor(Color::Red);*/

	/*Vector2f _sizeBoofly = Vector2f(150.0f, 180.0f);

	ShapeData _dataBoofly = ShapeData(Vector2f(200.0f, -350.0f), _sizeBoofly, PATH_BOOFLY, IntRect(0, 17, 315, 345));
	Boofly* _boofly = new Boofly(_dataBoofly);
	_boofly->Init();*/
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
	for (ShapeObject* _drawable : map->GetAllDrawables())
	{
		if (_drawable->IsHidden())
			continue;
		window.draw(*_drawable->GetDrawable());
	}
}

void Game::DrawActors()
{
	for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	{
		if (_actor->IsHidden())
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
			if (!_widget->IsVisible())
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