#pragma once
#include "Game.h"
#include "Singleton.h"

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
class Gameplay : public Singleton<Gameplay>
{
	GameMode currentMode;
	Game* game = nullptr;
	int currentMap;
	vector<Map*> allMaps;

public:
	Gameplay(Game* _game, vector<Map*> _allMaps);
	~Gameplay();

	void ModePassif();
	void ModeDefense();
	void ModeAttack();
	void SelectMap(int _map);

private:
	void SelectionTarget(Entity* _entity,const bool _isAlly);
};

