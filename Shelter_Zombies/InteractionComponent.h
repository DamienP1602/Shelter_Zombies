#pragma once
#include "Component.h"
#include"PNJ.h"

class InteractionComponent : public Component
{
	float range;
	PNJ* pnj;

public:
	InteractionComponent(Actor* _owner);
	~InteractionComponent();

public:
	void TryToInteract();
	void StopInteract();
};