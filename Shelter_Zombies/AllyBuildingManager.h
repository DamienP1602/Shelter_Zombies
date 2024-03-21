#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Building.h"
#include "Nexus.h"

class AllyBuildingManager : public Singleton<AllyBuildingManager>, public IManager<string, Building>
{
	Nexus* nexus;

public:
	AllyBuildingManager();

	bool IsNexusDestroy() const
	{
		if (!nexus)
			return false;
		return nexus->IsDestroy();
	}

	void SetNexus(Vector2f _position)
	{
		//TODO set nexus
		nexus = new Nexus(_position);
	}
};

