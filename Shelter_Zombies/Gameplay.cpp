#include "Gameplay.h"
#include "Game.h"
#include "AllyEntityManager.h"
#include "EnemyEntityManager.h"
#include "AllyConstructionManager.h"
#include "EnemyConstructionManager.h"
#include "AllyBuildingManager.h"
#include "EnemyBuildingManager.h"
#include "Kismet.h"
#include "Map.h"

Gameplay::Gameplay(Game* _game, vector<Map*> _allMaps)
{
	currentMode = GameMode::Passif;
	game = _game;
	currentMap = 0;
	allMaps = _allMaps;
}

Gameplay::~Gameplay()
{
	for (size_t i = 0; i < allMaps.size(); i++)
		allMaps[i] = nullptr;
	allMaps.clear();
	game = nullptr;
	delete game;
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
	vector<Construction*> _allConstruction = AllyConstructionManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allConstruction.size(); i++)
		_allConstruction[i]->RestoreLife();

	//Restore all HPs of building
	vector<Building*> _allBuilding = AllyBuildingManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allBuilding.size(); i++)
		_allBuilding[i]->RestoreLife();
}

void Gameplay::ModeDefense()
{
	currentMode = GameMode::Defense;

	//TODO active player attack UI

	//Active all construction
	vector<Construction*> _allConstruction = AllyConstructionManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allConstruction.size(); i++)
		_allConstruction[i]->SetActive(true);

	//Active all enemies and spawn them
	EnemyEntityManager::GetInstance().SpawnEntities(false);
	vector<Entity*> _allEnemy = EnemyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allEnemy.size(); i++)
	{
		_allEnemy[i]->SetActive(true);
		SelectionTarget(_allEnemy[i], false);
	}
}

void Gameplay::ModeAttack()
{
	currentMode = GameMode::Attack;

	//TODO active player attack UI

	//Active all enemies and spawn them
	EnemyEntityManager::GetInstance().SpawnEntities(true);
	vector<Entity*> _allEnemy = EnemyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allEnemy.size(); i++)
	{
		_allEnemy[i]->SetActive(true);
		SelectionTarget(_allEnemy[i], false);
	}

	//Active all allys and spawn them
	AllyEntityManager::GetInstance().SpawnEntities(true);
	vector<Entity*> _allAlly = AllyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allAlly.size(); i++)
	{
		_allAlly[i]->SetActive(true);
		SelectionTarget(_allEnemy[i], true);
	}
}

void Gameplay::SelectMap(int _map)
{
	currentMap = _map;
	allMaps[currentMap]->Load();
}

void Gameplay::SelectionTarget(Entity* _entity, bool _isAlly)
{
	Actor* _target = nullptr;
	float _distance = float(LONG_MAX);
	float _testDistance = 0;
	if (_isAlly)
	{
		vector<Entity*> _allEnemyEntity = EnemyEntityManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allEnemyEntity.size(); i++)
		{
			_testDistance = Distance(_entity->GetShapePosition(), _allEnemyEntity[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allEnemyEntity[i];
			}
		}

		vector<Building*> _allEnemyBuilding = EnemyBuildingManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allEnemyBuilding.size(); i++)
		{
			_testDistance = Distance(_entity->GetShapePosition(), _allEnemyBuilding[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allEnemyBuilding[i];
			}
		}

		vector<Construction*> _allEnemyConstruction = EnemyConstructionManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allEnemyConstruction.size(); i++)
		{
			_testDistance = Distance(_entity->GetShapePosition(), _allEnemyConstruction[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allEnemyConstruction[i];
			}
		}
	}
	else
	{
		vector<Entity*> _allAllyEntity = AllyEntityManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allAllyEntity.size(); i++)
		{
			_testDistance = Distance(_entity->GetShapePosition(), _allAllyEntity[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allAllyEntity[i];
			}
		}

		vector<Building*> _allAllyBuilding = AllyBuildingManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allAllyBuilding.size(); i++)
		{
			_testDistance = Distance(_entity->GetShapePosition(), _allAllyBuilding[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allAllyBuilding[i];
			}
		}

		vector<Construction*> _allAllyConstruction = AllyConstructionManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allAllyConstruction.size(); i++)
		{
			_testDistance = Distance(_entity->GetShapePosition(), _allAllyConstruction[i]->GetShapePosition());
			if (_testDistance < _distance)
			{
				_distance = _testDistance;
				_target = _allAllyConstruction[i];
			}
		}

		Player* _player = game->GetPlayer();
		_testDistance = Distance(_entity->GetShapePosition(), _player->GetShapePosition());
		if (_testDistance < _distance)
		{
			_distance = _testDistance;
			_target = _player;
		}
	}
	_entity->SetTarget(_target);
}
