#include "EnemyBuildingManager.h"

EnemyBuildingManager::EnemyBuildingManager()
{
	Vector2f _position = Vector2f(800, 800);
	//nexus = new Nexus(_position);
}

EnemyBuildingManager::~EnemyBuildingManager()
{
	nexus = nullptr;
	delete nexus;
}
