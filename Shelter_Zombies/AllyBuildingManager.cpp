#include "AllyBuildingManager.h"

AllyBuildingManager::AllyBuildingManager()
{
	nexus = new Nexus(Vector2f(0.0f,0.0f));
}

AllyBuildingManager::~AllyBuildingManager()
{
	nexus = nullptr;
	delete nexus;
}
