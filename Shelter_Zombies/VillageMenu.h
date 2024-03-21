#pragma once
#include "Menu.h"
#include <vector>
#include "ShapeWidget.h"
#include "Game.h"
#include "Wall.h"
#include "Timer.h"
#include "Skelet.h"

#include <iostream>

struct ConstructElements
{
	bool isInit;
	vector<ShapeWidget*> allBuildings;
	bool isInCanva;

	ConstructElements()
	{
		isInit = false;
		allBuildings = vector<ShapeWidget*>();
		isInCanva = false;
	}
};

struct ConstructPanel
{
	float windowX;
	float windowY;

private:
	bool isOpen;
	ShapeWidget* background;
	vector<ConstructElements*> allBuildings;
	int index;

public:
	void SetBackground(ShapeWidget* _background)
	{
		background = _background;
	}
	ShapeWidget* GetBackground() const
	{
		return background;
	}

	void TogglePanel()
	{
		isOpen = !isOpen;
	}

	void SetIndex(const int _index)
	{
		index = _index;
	}

	vector<ConstructElements*> GetAllWidget() const
	{
		return allBuildings;
	}

	void InitWalls()
	{
		if (!allBuildings[0]->isInit)
		{			
			function<void()> _callbacks[] = {
				[&](){new Timer([&]() {Game::GetPlayer()->SetConstructionMode(new Wall(Vector2f(), 0)); },seconds(0.1f)); },
				[&](){new Timer([&]() {Game::GetPlayer()->SetConstructionMode(new Wall(Vector2f(), 1)); },seconds(0.1f)); },
				[&](){new Skelet(Vector2f(Game::GetPlayer()->GetShapePosition() + Vector2f(500.0f,500.0f)),1); },
				[&](){; }
			};

			const Vector2f& _contructButtonPosition = Vector2f(windowX * 0.05f, windowY * 0.85f);

			for (int _i = 0; _i < 4; _i++)
			{
				const Vector2f& _gap = Vector2f((100.f * _i), 0.0f);
				allBuildings[0]->allBuildings.push_back(new Button(ShapeData(_contructButtonPosition + _gap, Vector2f(75.0f, 75.0f), "red.png"),ButtonData(NULL,NULL, _callbacks[_i], NULL, NULL)));
			}
			allBuildings[0]->isInit = true;
		}
		allBuildings[0]->isInCanva = true;

	}
	void InitDefenses()
	{
		if (!allBuildings[1]->isInit)
		{
			const Vector2f& _contructButtonPosition = Vector2f(windowX * 0.05f, windowY * 0.85f);

			for (int _i = 0; _i < 4; _i++)
			{
				const Vector2f& _gap = Vector2f((100.f * _i), 0.0f);
				allBuildings[1]->allBuildings.push_back(new Button(ShapeData(_contructButtonPosition + _gap, Vector2f(75.0f, 75.0f), "green.png")));
			}
			allBuildings[1]->isInit = true;
		}
		allBuildings[1]->isInCanva = true;

	}
	void InitTraps()
	{
		if (!allBuildings[2]->isInit)
		{
			const Vector2f& _contructButtonPosition = Vector2f(windowX * 0.05f, windowY * 0.85f);

			for (int _i = 0; _i < 4; _i++)
			{
				const Vector2f& _gap = Vector2f((100.f * _i), 0.0f);
				allBuildings[2]->allBuildings.push_back(new Button(ShapeData(_contructButtonPosition + _gap, Vector2f(75.0f, 75.0f), "blue.png")));
			}
			allBuildings[2]->isInit = true;
		}
		allBuildings[2]->isInCanva = true;

	}
	
	void InitCasern()
	{
		if (!allBuildings[3]->isInit)
		{
			const Vector2f& _contructButtonPosition = Vector2f(windowX * 0.05f, windowY * 0.85f);

			for (int _i = 0; _i < 4; _i++)
			{
				const Vector2f& _gap = Vector2f((100.f * _i), 0.0f);
				allBuildings[3]->allBuildings.push_back(new Button(ShapeData(_contructButtonPosition + _gap, Vector2f(75.0f, 75.0f), "yellow.png")));
			}
			allBuildings[3]->isInit = true;
		}
		allBuildings[3]->isInCanva = true;

	}

public:
	ConstructPanel()
	{
		windowX = Game::GetWindowSize().x;
		windowY = Game::GetWindowSize().y;

		isOpen = false;
		background = nullptr;
		
		for (int _i = 0; _i < 4; _i++)
		{
			allBuildings.push_back(new ConstructElements());
		}
		

		index = 0;
	}
};

class VillageMenu : public Menu
{
	ConstructPanel* panel;

public:
	VillageMenu();
	~VillageMenu();

public:
	void Init();
	void RemoveFromCanva();
	void AddToCanva();
};

