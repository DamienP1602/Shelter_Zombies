#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Decor.h"

class DecorManager : public Singleton<DecorManager>, public IManager<string, Decor>
{
public:
	DecorManager();
};

