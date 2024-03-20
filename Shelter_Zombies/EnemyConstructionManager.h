#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Construction.h"

class EnemyConstructionManager : public Singleton<EnemyConstructionManager>, public IManager<string, Construction>
{
public:
	EnemyConstructionManager();
};

