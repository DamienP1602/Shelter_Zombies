#include "Gameplay.h"
#include "AllyEntityManager.h"
#include "EnemyEntityManager.h"
#include "ConstructionManager.h"
#include "BuildingManager.h"
#include "Kismet.h"

Gameplay::Gameplay(Game* _game)
{
	game = _game;
	currentMode = GameMode::Passif;
}

Gameplay::~Gameplay()
{
	for (size_t i = 0; i < allMaps.size(); i++)
		allMaps[i] = nullptr;
	allMaps.clear();
	game = nullptr;
	currentMap = nullptr;
	delete game;
	delete currentMap;
}

void Gameplay::ModePassif()
{
	currentMode = GameMode::Passif;
	//TODO active player construction UI

	//TODO Restore HP of player
	//game->GetPlayer()->RestoreLife();

	//Restore all HPs of ally
	vector<Entity*> _allAlly = AllyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allAlly.size(); i++)
		_allAlly[i]->GetComponent<EntityLifeComponent>()->RestoreLife();

	//Restore all HPs of construction
	vector<Construction*> _allConstruction = ConstructionManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allConstruction.size(); i++)
		_allConstruction[i]->RestoreLife();

	//Restore all HPs of building
	vector<Building*> _allBuilding = BuildingManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allBuilding.size(); i++)
		_allBuilding[i]->RestoreLife();
}

void Gameplay::ModeDefense()
{
	currentMode = GameMode::Defense;

	//TODO active player attack UI

	//Active all construction
	vector<Construction*> _allConstruction = ConstructionManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allConstruction.size(); i++)
		_allConstruction[i]->SetActive(true);

	//Active all enemies and spawn them
	EnemyEntityManager::GetInstance().SpawnEntities(false);
	vector<Entity*> _allEnemy = EnemyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allEnemy.size(); i++)
		_allEnemy[i]->SetActive(true);
}

void Gameplay::ModeAttack()
{
	currentMode = GameMode::Attack;

	//Active all enemies and spawn them
	EnemyEntityManager::GetInstance().SpawnEntities(true);
	vector<Entity*> _allEnemy = EnemyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allEnemy.size(); i++)
		_allEnemy[i]->SetActive(true);

	//Active all allys and spawn them
	AllyEntityManager::GetInstance().SpawnEntities(true);
	vector<Entity*> _allAlly = AllyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allAlly.size(); i++)
		_allAlly[i]->SetActive(true);
}

void Gameplay::SelectionTarget(Entity* _entity, bool _isAlly)
{
	Actor* _target = nullptr;
	float _distance = LONG_MAX;
	if (_isAlly)
	{
		vector<Entity*> _allEnemyEntity = EnemyEntityManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allEnemyEntity.size(); i++)
		{
			float _testDistance = Distance(_entity->GetShapePosition(), _allEnemyEntity[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allEnemyEntity[i];
			}
		}

		//TODO EnemyBuildingManager
		//vector<Building*> _allEnemyBuilding = EnemyBuildingManager::GetInstance().GetAllValues();
		//for (size_t i = 0; i < _allEnemyBuilding.size(); i++)
		//{
		//	float _testDistance = Distance(_entity->GetShapePosition(), _allEnemyBuilding[i]->GetShapePosition());
		//	if (_testDistance < _distance)
		//	{
		//		_distance = _testDistance;
		//		_target = _allEnemyBuilding[i];
		//	}
		//}

		//TODO EnemyConstructionManager
		//vector<Construction*> _allEnemyConstruction = EnemyConstructionManager::GetInstance().GetAllValues();
		//for (size_t i = 0; i < _allEnemyConstruction.size(); i++)
		//{
		//	float _testDistance = Distance(_entity->GetShapePosition(), _allEnemyConstruction[i]->GetShapePosition());
		//	if (_testDistance < _distance)
		//	{
		//		_distance = _testDistance;
		//		_target = _allEnemyConstruction[i];
		//	}
		//}
	}
	else
	{
		vector<Entity*> _allAllyEntity = AllyEntityManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allAllyEntity.size(); i++)
		{
			float _testDistance = Distance(_entity->GetShapePosition(), _allAllyEntity[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allAllyEntity[i];
			}
		}

		vector<Building*> _allAllyBuilding = BuildingManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allAllyBuilding.size(); i++)
		{
			float _testDistance = Distance(_entity->GetShapePosition(), _allAllyBuilding[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allAllyBuilding[i];
			}
		}

		vector<Construction*> _allAllyConstruction = ConstructionManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allAllyConstruction.size(); i++)
		{
			float _testDistance = Distance(_entity->GetShapePosition(), _allAllyConstruction[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allAllyConstruction[i];
			}
		}
	}
	_entity->SetTarget(_target);
}