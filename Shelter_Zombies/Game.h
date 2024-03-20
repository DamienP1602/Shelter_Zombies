#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Camera.h"

using namespace std;
using namespace sf;

/// <summary>
/// The Game class
/// </summary>
class Game
{
	static RenderWindow window;
	static Map* map;

private:
	static Player* player;
	static Camera* camera;

public:
	static RenderWindow& GetWindow()
	{
		return window;
	}
	static Vector2f GetWindowSize()
	{
		return Vector2f(window.getSize());
	}
	static Player* GetPlayer()
	{
		return player;
	}
	static Camera* GetCamera()
	{
		return camera;
	}
	static Map* GetMap() 
	{
		return map;
	}

public:
	Game();
	~Game();

public:
	void Start();
	void Init();
	void Update();
	void UpdateWindow();

	#pragma region Draws
	void DrawMap();
	void DrawActors();
	void DrawUIs();
	#pragma endregion

	void Stop();

public:
	void Launch();
	static void Close();
};