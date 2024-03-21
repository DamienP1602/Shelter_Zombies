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
		Vector2f _position = Vector2f(400, 100 * i); //Column
		allFighters[i]->SetShapePosition(_position);
		allFighters[i]->SetActive(true);
		allFighters[i]->SetIsHidden(false);
	}
	for (int i = 0; i < allShooters.size(); i++)
	{
		Vector2f _position = Vector2f(300, 100 * i); //Column
		allShooters[i]->SetShapePosition(_position);
		allShooters[i]->SetActive(true);
		allShooters[i]->SetIsHidden(false);
	}
	for (int i = 0; i < allSupports.size(); i++)
	{
		Vector2f _position = Vector2f(200, 100 * i); //Column
		allSupports[i]->SetShapePosition(_position);
		allSupports[i]->SetActive(true);
		allSupports[i]->SetIsHidden(false);
	}
	for (int i = 0; i < allArtilleries.size(); i++)
	{
		Vector2f _position = Vector2f(100, 100 * i); //Column
		allArtilleries[i]->SetShapePosition(_position);
		allArtilleries[i]->SetActive(true);
		allArtilleries[i]->SetIsHidden(false);
	}
}
