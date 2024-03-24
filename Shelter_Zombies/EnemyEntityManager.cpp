#include "EnemyEntityManager.h"
#include "Skelet.h"
#include "Orc.h"
#include "Warlock.h"
#include "Golem.h"

EnemyEntityManager::EnemyEntityManager()
{
	needToDelete = false;
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

void EnemyEntityManager::SetArmy(const int _skelets, const int _orcs, const int _warlocks, const int _golems, const int _level)
{
	for (int i = 0; i < _skelets; i++)
	{
		Skelet* _skelet = new Skelet(Vector2f(0, 0), _level);
		_skelet->Init();
		allFighters.push_back(_skelet);
		Add(_skelet->GetID(), _skelet);
	}
	for (int i = 0; i < _orcs; i++)
	{
		Orc* _orc = new Orc(Vector2f(0, 0), _level);
		allShooters.push_back(_orc);
		Add(_orc->GetID(), _orc);
	}
	for (int i = 0; i < _warlocks; i++)
	{
		Warlock* _warlock = new Warlock(Vector2f(0, 0), _level);
		allSupports.push_back(_warlock);
		Add(_warlock->GetID(), _warlock);
	}
	for (int i = 0; i < _golems; i++)
	{
		Golem* _golem = new Golem(Vector2f(0, 0), _level);
		allArtilleries.push_back(_golem);
		Add(_golem->GetID(), _golem);
	}
}

void EnemyEntityManager::SpawnEntities(bool _isAttack)
{
	const Vector2f& _origin = _isAttack ? Vector2f(0.0f, 1000.0f) : Vector2f(0.0f, 600.0f);

	int _size = int(allFighters.size());
	for (int i = 0; i < _size; i++)
	{
		const Vector2f& _position = _origin + Vector2f(1920.f / _size * (i + 1.f), -300.f); //Column
		allFighters[i]->SetShapePosition(_position);
		allFighters[i]->SetActive(false);
		allFighters[i]->SetIsHidden(false);
	}
	_size = int(allShooters.size());
	for (int i = 0; i < _size; i++)
	{
		const Vector2f& _position = _origin + Vector2f(1920.f / _size * (i + 1.f), -200.f);
		allShooters[i]->SetShapePosition(_position);
		allShooters[i]->SetActive(false);
		allShooters[i]->SetIsHidden(false);
	}
	_size = int(allSupports.size());
	for (int i = 0; i < _size; i++)
	{
		const Vector2f& _position = _origin + Vector2f(1920.f / _size * (i + 1.f), -100.f);
		allSupports[i]->SetShapePosition(_position);
		allSupports[i]->SetActive(false);
		allSupports[i]->SetIsHidden(false);
	}
	_size = int(allArtilleries.size());
	for (int i = 0; i < _size; i++)
	{
		const Vector2f& _position = _origin + Vector2f(1920.f / _size * (i + 1.f), 0.f);
		allArtilleries[i]->SetShapePosition(_position);
		allArtilleries[i]->SetActive(false);
		allArtilleries[i]->SetIsHidden(false);
	}
}
