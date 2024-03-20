#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Building.h"

class AllyBuildingManager : public Singleton<AllyBuildingManager>, public IManager<string, Building>
{
public:
	AllyBuildingManager();
};

