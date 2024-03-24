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
#include "io.h"
#include "Priest.h"
#include "Warlock.h"
#include "VillageMenu.h"
#include "MenuManager.h"
#include "AttackMenu.h"

Gameplay::Gameplay()
{
	game = nullptr;
	currentMap = 0;
	waveCooldown = 20.f; //seconds
	waveTimerEnd = false;
	waveTimer = new Timer([&]() { WaveTimerEnd(); }, seconds(waveCooldown), false, false);
}

Gameplay::~Gameplay()
{
	for (size_t i = 0; i < allMaps.size(); i++)
		allMaps[i] = nullptr;
	allMaps.clear();
	game = nullptr;
	delete game;
}

void Gameplay::AddMap(Map* _map)
{
	allMaps.push_back(_map);
}

bool Gameplay::CheckEnemyArmy()
{
	return EnemyEntityManager::GetInstance().Count() == 0;
}

bool Gameplay::CheckEnemyBase()
{
	return EnemyBuildingManager::GetInstance().IsNexusDestroy();
}

bool Gameplay::CheckAllyArmy()
{
	return AllyEntityManager::GetInstance().Count() == 0 /*&& game->GetPlayer()->IsDead()*/;
}

bool Gameplay::CheckAllyBase()
{
	return AllyBuildingManager::GetInstance().IsNexusDestroy();
}

void Gameplay::ModePassif()
{
	currentMode = GameMode::Passif;
	waveTimerEnd = false;
	waveTimer->Start();

	if (VillageMenu* _menu = dynamic_cast<VillageMenu*>(MenuManager::GetInstance().Get("PlayerVillageMenu")))
	{
		MenuManager::GetInstance().SetCurrent(_menu);
		MenuManager::GetInstance().DisableNotCurrent();
	}
	else
	{
		new VillageMenu();
	}

	Game::GetPlayer()->GetData()->RestoreHealth();

	//Restore all HPs of ally and despawn them
	vector<Entity*> _allAlly = AllyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allAlly.size(); i++)
	{
		_allAlly[i]->GetComponent<EntityLifeComponent>()->RestoreLife();
		_allAlly[i]->SetActive(false);
		_allAlly[i]->SetIsHidden(true);
	}

	//Restore all HPs of construction
	vector<Construction*> _allConstruction = AllyConstructionManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allConstruction.size(); i++)
		_allConstruction[i]->RestoreLife();

	//Restore all HPs of building
	vector<Building*> _allBuilding = AllyBuildingManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allBuilding.size(); i++)
		_allBuilding[i]->RestoreLife();

	//Restore all enemies HPs and despawn them
	vector<Entity*> _allEnemy = EnemyEntityManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allEnemy.size(); i++)
	{
		_allEnemy[i]->GetComponent<EntityLifeComponent>()->RestoreLife();
		_allEnemy[i]->SetActive(false);
		_allEnemy[i]->SetIsHidden(true);
	}
}

void Gameplay::ModeDefense()
{
	currentMode = GameMode::Defense;
	waveTimer->Reset();

	if (AttackMenu* _menu = dynamic_cast<AttackMenu*>(MenuManager::GetInstance().Get("AttackMenu")))
	{
		MenuManager::GetInstance().SetCurrent(_menu);
		MenuManager::GetInstance().DisableNotCurrent();
	}
	else
	{
		new AttackMenu();
	}

	//Active all construction
	vector<Construction*> _allConstruction = AllyConstructionManager::GetInstance().GetAllValues();
	for (size_t i = 0; i < _allConstruction.size(); i++)
		_allConstruction[i]->SetActive(true);

	//Active all enemies and spawn them
	EnemyEntityManager::GetInstance().SpawnEntities(true);
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
	waveTimer->Reset();

	if (AttackMenu* _menu = dynamic_cast<AttackMenu*>(MenuManager::GetInstance().Get("AttackMenu")))
	{
		MenuManager::GetInstance().SetCurrent(_menu);
		MenuManager::GetInstance().DisableNotCurrent();
	}
	else
	{
		new AttackMenu();
	}

	//Active all enemies and spawn them
	EnemyEntityManager::GetInstance().SpawnEntities(false);
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
	if (_map == currentMap) return;

	allMaps[currentMap]->DeLoad();
	currentMap = _map;
	allMaps[currentMap]->Load();
}

void Gameplay::Init(Game* _game)
{
	currentMode = GameMode::Passif;
	game = _game;
	currentMap = 0;
	//allMaps = _allMaps;

	EnemyEntityManager::GetInstance().SetArmy(1, 1, 1, 1, 0);
	ModePassif();
}

void Gameplay::Update()
{
	ChangeMode();
}

void Gameplay::ChangeMode()
{
	if (currentMode == GameMode::Passif && IsTimerWaveEnd())
	{
		cout << "WARNING: incoming enemy attack, prepare to defend your base" << endl;
		ModeDefense();
	}
	else if (currentMode == GameMode::Defense && CheckEnemyArmy())
	{
		cout << "Enemy army defeat: You successfully defend your base !" << endl;
		ModePassif();
	}
	else if (currentMode == GameMode::Defense && CheckAllyBase())
	{
		cout << "Your nexus have been destroy: Game-Over !!" << endl;
		//LoadPreviousMap();
		ModePassif();
		game->Close();
	}
	else if (currentMode == GameMode::Attack && CheckEnemyBase())
	{
		cout << "Enemy nexus destroy: You successfully win victory and this new base !" << endl;
		ModePassif();
	}
	else if (currentMode == GameMode::Attack && CheckAllyArmy())
	{
		cout << "You have lost the battle but not the war: go back to your base !" << endl;
		SelectMap(0);
		ModePassif();
	}
}

void Gameplay::SelectionTarget(Entity* _entity, bool _isAlly)
{
	Actor* _target = nullptr;
	float _distance = float(LONG_MAX);
	float _testDistance = 0;

	if (dynamic_cast<Warlock*>(_entity))
	{
		vector<Entity*> _allEnemyEntity = EnemyEntityManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allEnemyEntity.size(); i++)
		{
			if (_allEnemyEntity[i]->IsHidden())
				continue;
			_testDistance = Distance(_entity->GetShapePosition(), _allEnemyEntity[i]->GetShapePosition());
			if (_testDistance < _distance && _allEnemyEntity[i]->GetComponent<EntityLifeComponent>()->NeedHealing())
			{
				_distance = _testDistance;
				_target = _allEnemyEntity[i];
			}
		}
	}
	else if (dynamic_cast<Priest*>(_entity))
	{
		vector<Entity*> _allAllyEntity = AllyEntityManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allAllyEntity.size(); i++)
		{
			if (_allAllyEntity[i]->IsHidden())
				continue;
			_testDistance = Distance(_entity->GetShapePosition(), _allAllyEntity[i]->GetShapePosition());
			if (_testDistance < _distance && _allAllyEntity[i]->GetComponent<EntityLifeComponent>()->NeedHealing())
			{
				_distance = _testDistance;
				_target = _allAllyEntity[i];
			}
		}
	}
	else if (_isAlly)
	{
		vector<Entity*> _allEnemyEntity = EnemyEntityManager::GetInstance().GetAllValues();
		for (size_t i = 0; i < _allEnemyEntity.size(); i++)
		{
			if (_allEnemyEntity[i]->IsHidden())
				continue;
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
	else if (!_isAlly)
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

void Gameplay::WaveTimerEnd()
{
	waveTimerEnd = true;
}
