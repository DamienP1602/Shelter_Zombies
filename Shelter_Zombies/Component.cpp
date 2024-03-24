#include "Component.h"
#include "Actor.h"

Component::Component(Actor* _owner)
{
	owner = _owner;
}

Component::~Component()
{
	owner = nullptr;
	delete owner;
}
