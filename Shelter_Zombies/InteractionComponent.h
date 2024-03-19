#pragma once
#include "Component.h"
#include "Inventory.h"
#include"PNJ.h"

class InteractionComponent : public Component
{
	float range;
	Inventory* inventory;
	PNJ* pnj;

public:
	InteractionComponent(Actor* _owner);

public:
	void TryToInteract();
	void StopInteract();
};