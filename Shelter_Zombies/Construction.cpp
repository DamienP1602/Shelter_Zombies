#include "Construction.h"
#include "Entity.h"

Construction::Construction(const string& _name, const ShapeData& _shape, const bool _isAlly, Canvas* _canvas) :
	InteractableActor(_name, _shape, _canvas)
{
	layer = 1;
	isAlly = _isAlly;
}

Construction::~Construction()
{
	data = nullptr;
}

void Construction::TakeDamage(int _damage)
{
	data->currentLife -= _damage;
	if (data->currentLife <= 0)
		isDestroy = true;
}

void Construction::Repare()
{
	data->currentLife = data->maxLife;
}

void Construction::Attack(Entity* _target)
{
}
