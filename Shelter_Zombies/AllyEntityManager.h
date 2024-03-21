#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

class Knight;
class Archer;
class Priest;
class Catapult;

using namespace std;

class AllyEntityManager : public Singleton<AllyEntityManager>, public IManager<string, Entity>
{
private:
	int maxEntities;
	vector<Knight*> allFighters;
	vector<Archer*> allShooters;
	vector<Priest*> allSupports;
	vector<Catapult*> allArtilleries;

public:
	AllyEntityManager();
	~AllyEntityManager();

	void SetMaxEntities(const int _max)
	{
		maxEntities = _max;
	}
	int GetMaxEntities()
	{
		return maxEntities;
	}
	int GetEntitiesCount()
	{
		return int(allFighters.size() + allShooters.size() + allSupports.size() + allArtilleries.size());
	}
	bool IsMaxEntities()
	{
		return GetEntitiesCount() == maxEntities;
	}

	bool AddKnight(Knight* _fighter);
	bool AddArcher(Archer* _shooter);
	bool AddChurch(Priest* _support);
	bool AddCatapult(Catapult* _artillery);
	void SpawnEntities(const bool _isAttack);
};