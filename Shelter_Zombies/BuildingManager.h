#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Building.h"

class BuildingManager : public Singleton<BuildingManager>, public IManager<string, Building>
{

public:
	BuildingManager();
};

