#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Construction.h"

class AllyConstructionManager : public Singleton<AllyConstructionManager>, public IManager<string, Construction>
{

public:
	AllyConstructionManager();
};

