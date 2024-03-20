#include "Building.h"

Building::Building(const string& _name, const ShapeData& _shape, Canvas* _canvas) :
	InteractableActor(_name, _shape, _canvas)
{
	layer = 1;
}

Building::~Building()
{
	data = nullptr;
}

void Building::TakeDamage(int _damage)
{
	data->currentLife -= _damage;
	if (data->currentLife <= 0)
		isDestroy = true;
}

void Building::Repare()
{
	data->currentLife = data->maxLife;
}
