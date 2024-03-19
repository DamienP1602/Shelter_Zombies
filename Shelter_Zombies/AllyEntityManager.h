#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

class Fighter;
class Shooter;
class Support;
class Artillery;

using namespace std;

class AllyEntityManager : public Singleton<AllyEntityManager>, public IManager<string, Entity>
{
private:
	int maxEntities = 10;
	vector<Fighter*> allFighters;
	vector<Shooter*> allShooters;
	vector<Support*> allSupports;
	vector<Artillery*> allArtilleries;

public:
	AllyEntityManager();
	~AllyEntityManager();

	void SetMaxEntities(int _max)
	{
		maxEntities = _max;
	}
	int GetMaxEntities()
	{
		return maxEntities;
	}
	bool GetEntitiesCount()
	{
		return allFighters.size() + allShooters.size() + allSupports.size() + allArtilleries.size();
	}
	bool IsMaxEntities()
	{
		return GetEntitiesCount() == maxEntities;
	}

	bool AddFighter(Fighter* _fighter);
	bool AddShooter(Shooter* _shooter);
	bool AddSupport(Support* _support);
	bool AddArtillery(Artillery* _artillery);
	void SpawnEntities();
};