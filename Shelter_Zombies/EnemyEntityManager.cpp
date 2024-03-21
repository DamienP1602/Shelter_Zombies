#include "EnemyEntityManager.h"
#include "Skelet.h"
#include "Orc.h"
#include "Warlock.h"
#include "Golem.h"

EnemyEntityManager::EnemyEntityManager()
{
}

EnemyEntityManager::~EnemyEntityManager()
{
	for (int i = 0; i < allFighters.size(); i++)
	{
		allFighters[i]->Destroy();
		allFighters[i] = nullptr;
	}
	for (int i = 0; i < allShooters.size(); i++)
	{
		allShooters[i]->Destroy();
		allShooters[i] = nullptr;
	}
	for (int i = 0; i < allSupports.size(); i++)
	{
		allSupports[i]->Destroy();
		allSupports[i] = nullptr;
	}
	for (int i = 0; i < allArtilleries.size(); i++)
	{
		allArtilleries[i]->Destroy();
		allArtilleries[i] = nullptr;
	}
}

void EnemyEntityManager::Init(vector<Skelet*> _allFighters, vector<Orc*> _allShooters, vector<Warlock*> _allSupports, vector<Golem*> _allArtilleries)
{
	allFighters = _allFighters;
	allShooters = _allShooters;
	allSupports = _allSupports;
	allArtilleries = _allArtilleries;
}

void EnemyEntityManager::SetArmy(const int _skelets, const int _orcs, const int _warlocks, const int _golems)
{
	for (int i = 0; i < _skelets; i++)
	{
		Skelet* _skelet = new Skelet(Vector2f(0, 0), 0);
		allFighters.push_back(_skelet);
		Add(_skelet->GetID(), _skelet);
	}
	for (int i = 0; i < _orcs; i++)
	{
		Orc* _orc = new Orc(Vector2f(0, 0), 0);
		allShooters.push_back(_orc);
		Add(_orc->GetID(), _orc);
	}
	for (int i = 0; i < _warlocks; i++)
	{
		Warlock* _warlock = new Warlock(Vector2f(0, 0), 0);
		allSupports.push_back(_warlock);
		Add(_warlock->GetID(), _warlock);
	}
	for (int i = 0; i < _golems; i++)
	{
		Golem* _golem = new Golem(Vector2f(0, 0), 0);
		allArtilleries.push_back(_golem);
		Add(_golem->GetID(), _golem);
	}
}

void EnemyEntityManager::SpawnEntities(bool _isAttack)
{
	//TODO need screen location
	//Vector2f _position;
	//if (_isAttack)
	//	_position = 
	//else
	//	_position = 

	for (int i = 0; i < allFighters.size(); i++)
	{
		Vector2f _position = Vector2f(400.0f, 100.0f * i); //Column
		allFighters[i]->SetShapePosition(_position);
		allFighters[i]->SetActive(true);
		allFighters[i]->SetIsHidden(false);
	}
	for (int i = 0; i < allShooters.size(); i++)
	{
		Vector2f _position = Vector2f(300.0f, 100.0f * i); //Column
		allShooters[i]->SetShapePosition(_position);
		allShooters[i]->SetActive(true);
		allShooters[i]->SetIsHidden(false);
	}
	for (int i = 0; i < allSupports.size(); i++)
	{
		Vector2f _position = Vector2f(200.0f, 100.0f * i); //Column
		allSupports[i]->SetShapePosition(_position);
		allSupports[i]->SetActive(true);
		allSupports[i]->SetIsHidden(false);
	}
	for (int i = 0; i < allArtilleries.size(); i++)
	{
		Vector2f _position = Vector2f(100.0f, 100.0f * i); //Column
		allArtilleries[i]->SetShapePosition(_position);
		allArtilleries[i]->SetActive(true);
		allArtilleries[i]->SetIsHidden(false);
	}
}
