#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

class Fighter;
class Shooter;
class Support;
class Artillery;

using namespace std;

class EnemyEntityManager : public Singleton<EnemyEntityManager>, public IManager<string, Entity>
{
private:
	vector<Fighter*> allFighters;
	vector<Shooter*> allShooters;
	vector<Support*> allSupports;
	vector<Artillery*> allArtilleries;

public:
	EnemyEntityManager();
	~EnemyEntityManager();

	void Init(vector<Fighter*> _allFighters, vector<Shooter*> _allShooters, vector<Support*> _allSupports, vector<Artillery*> _allArtilleries);
	void SpawnEntities(bool _isAttack);
};
