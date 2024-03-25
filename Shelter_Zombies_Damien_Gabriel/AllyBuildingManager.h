#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Building.h"
#include "Nexus.h"
#include "Gameplay.h"

class AllyBuildingManager : public Singleton<AllyBuildingManager>, public IManager<string, Building>
{
	Nexus* nexus;

public:
	AllyBuildingManager();
	~AllyBuildingManager();

	bool IsNexusDestroy() const
	{
		if (!nexus)
			return false;
		return nexus->IsDestroy();
	}

	void SetNexus(Vector2f _position)
	{
		Gameplay::GetInstance().GetMap(0)->PutInMap(nexus, Vector2i(_position));
		nexus = new Nexus(_position);
	}
};

