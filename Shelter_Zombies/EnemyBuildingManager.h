#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Building.h"

class EnemyBuildingManager : public Singleton<EnemyBuildingManager>, public IManager<string, Building>
{
public:
	EnemyBuildingManager();
};

