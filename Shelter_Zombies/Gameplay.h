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
	int waveCooldown;
	Timer* waveTimer;
	bool waveTimerEnd;

public:
	Gameplay();
	~Gameplay();

	bool IsTimerWaveEnd()
	{
		return waveTimerEnd;
	}
	bool CheckEnemyArmy();
	bool CheckEnemyBase();
	bool CheckAllyArmy();
	bool CheckAllyBase();

	void Init(Game* _game);
	void Update();
	void ChangeMode();

	void ModePassif();
	void ModeDefense();
	void ModeAttack();
	void SelectMap(int _map);
	void SelectionTarget(Entity* _entity,const bool _isAlly);
	void WaveTimerEnd();
};

