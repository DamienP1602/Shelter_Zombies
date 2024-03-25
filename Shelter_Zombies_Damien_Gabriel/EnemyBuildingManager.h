#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Building.h"
#include "Nexus.h"

class EnemyBuildingManager : public Singleton<EnemyBuildingManager>, public IManager<string, Building>
{
	Nexus* nexus;
public:
	EnemyBuildingManager();
	~EnemyBuildingManager();

	bool IsNexusDestroy() const
	{
		return nexus->IsDestroy();
	}
};

