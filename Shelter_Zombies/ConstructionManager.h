#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Construction.h"

class ConstructionManager : public Singleton<ConstructionManager>, public IManager<string, Construction>
{

public:
	ConstructionManager();
};

