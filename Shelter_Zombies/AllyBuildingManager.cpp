#include "AllyBuildingManager.h"

AllyBuildingManager::AllyBuildingManager()
{
	nexus = nullptr;
}

AllyBuildingManager::~AllyBuildingManager()
{
	nexus = nullptr;
	delete nexus;
}
