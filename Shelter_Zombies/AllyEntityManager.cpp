#include "AllyEntityManager.h"
#include "Knight.h"
#include "Archer.h"
#include "Priest.h"
#include "Catapult.h"

AllyEntityManager::AllyEntityManager()
{
	maxEntities = 10;
}

AllyEntityManager::~AllyEntityManager()
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

bool AllyEntityManager::AddKnight(Knight* _fighter)
{
	if (IsMaxEntities())
		return false;
	allFighters.push_back(_fighter);
	Add(_fighter->GetID(), _fighter);
	return true;
}

bool AllyEntityManager::AddArcher(Archer* _shooter)
{
	if (IsMaxEntities())
		return false;
	allShooters.push_back(_shooter);
	Add(_shooter->GetID(), _shooter);
	_shooter->SetIsHidden(true);
	return true;
}

bool AllyEntityManager::AddChurch(Priest* _support)
{
	if (IsMaxEntities())
		return false;
	allSupports.push_back(_support);
	Add(_support->GetID(), _support);
	_support->SetIsHidden(true);
	return true;
}

bool AllyEntityManager::AddCatapult(Catapult* _artillery)
{
	if (IsMaxEntities())
		return false;
	allArtilleries.push_back(_artillery);
	Add(_artillery->GetID(), _artillery);
	_artillery->SetIsHidden(true);
	return true;
}

void AllyEntityManager::SpawnEntities(const bool _isAttack)
{
	const Vector2f& _origin = _isAttack ? Vector2f(0.0f, 1000.0f) : Vector2f(0.0f, 600.0f);

	int _size = int(allFighters.size());
	for (int i = 0; i < _size; i++)
	{
		const Vector2f& _position = _origin + Vector2f(1920.f / _size * (i + 1.f), -300.f); //Column
		allFighters[i]->SetShapePosition(_position);
		allFighters[i]->SetActive(true);
		allFighters[i]->SetIsHidden(false);
	}
	_size = int(allShooters.size());
	for (int i = 0; i < _size; i++)
	{
		const Vector2f& _position = _origin + Vector2f(1920.f / _size * (i + 1.f), -200.f);
		allShooters[i]->SetShapePosition(_position);
		allShooters[i]->SetActive(true);
		allShooters[i]->SetIsHidden(false);
	}
	_size = int(allSupports.size());
	for (int i = 0; i < _size; i++)
	{
		const Vector2f& _position = _origin + Vector2f(1920.f / _size * (i + 1.f), -100.f);
		allSupports[i]->SetShapePosition(_position);
		allSupports[i]->SetActive(true);
		allSupports[i]->SetIsHidden(false);
	}
	_size = int(allArtilleries.size());
	for (int i = 0; i < _size; i++)
	{
		const Vector2f& _position = _origin + Vector2f(1920.f / _size * (i + 1.f), 0.f);
		allArtilleries[i]->SetShapePosition(_position);
		allArtilleries[i]->SetActive(true);
		allArtilleries[i]->SetIsHidden(false);
	}
}
