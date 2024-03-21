#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

class Skelet;
class Orc;
class Warlock;
class Golem;

using namespace std;

class EnemyEntityManager : public Singleton<EnemyEntityManager>, public IManager<string, Entity>
{
private:
	vector<Skelet*> allFighters;
	vector<Orc*> allShooters;
	vector<Warlock*> allSupports;
	vector<Golem*> allArtilleries;

public:
	EnemyEntityManager();
	~EnemyEntityManager();

	void Init(vector<Skelet*> _allFighters, vector<Orc*> _allShooters, vector<Warlock*> _allSupports, vector<Golem*> _allArtilleries);
	void SpawnEntities(bool _isAttack);
};
