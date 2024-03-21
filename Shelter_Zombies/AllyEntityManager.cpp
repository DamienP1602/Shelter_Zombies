#include "AllyEntityManager.h"
#include "Knight.h"
#include "Archer.h"
#include "Church.h"
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
	_fighter->SetIsHidden(true);
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

bool AllyEntityManager::AddChurch(Church* _support)
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
	//TODO need screen location
	//Vector2f _position;
	//if (_isAttack)
	//	_position = 
	//else
	//	_position = 

	for (size_t i = 0; i < allFighters.size(); i++)
	{
		Vector2f _position = Vector2f(400.f, 100.f * i); //Column
		allFighters[i]->SetShapePosition(_position);
		allFighters[i]->SetActive(true);
		allFighters[i]->SetIsHidden(false);
	}
	for (size_t i = 0; i < allShooters.size(); i++)
	{
		Vector2f _position = Vector2f(300.f, 100.f * i); //Column
		allShooters[i]->SetShapePosition(_position);
		allShooters[i]->SetActive(true);
		allShooters[i]->SetIsHidden(false);
	}
	for (size_t i = 0; i < allSupports.size(); i++)
	{
		Vector2f _position = Vector2f(200.f, 100.f * i); //Column
		allSupports[i]->SetShapePosition(_position);
		allSupports[i]->SetActive(true);
		allSupports[i]->SetIsHidden(false);
	}
	for (size_t i = 0; i < allArtilleries.size(); i++)
	{
		Vector2f _position = Vector2f(100.f, 100.f * i); //Column
		allArtilleries[i]->SetShapePosition(_position);
		allArtilleries[i]->SetActive(true);
		allArtilleries[i]->SetIsHidden(false);
	}
}
