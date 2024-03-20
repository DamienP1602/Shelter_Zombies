#pragma once
#include "Game.h"

using namespace std;
using namespace sf;

enum GameMode
{
	Passif,
	Defense,
	Attack
};

/// <summary>
/// The class to handle game-modes and maps
/// </summary>
class Gameplay
{
	GameMode currentMode;
	Game* game = nullptr;
	Map* currentMap = nullptr;
	vector<Map*> allMaps;

public:
	Gameplay(Game* _game);
	~Gameplay();

private:
	void ModePassif();
	void ModeDefense();
	void ModeAttack();

	void SelectionTarget(Entity* _entity, bool _isAlly);
};

