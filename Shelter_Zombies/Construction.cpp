#include "Construction.h"
#include "Entity.h"

Construction::Construction(const string& _name, const ShapeData& _shape, Canvas* _canvas) :
	InteractableActor(_name, _shape, _canvas)
{
	layer = 1;
}

Construction::~Construction()
{
	data = nullptr;
}

void Construction::TakeDamage(int _damage)
{
	data->currentHP -= _damage;
	if (data->currentHP <= 0)
		isDestroy = true;
}

void Construction::Repare()
{
	data->currentHP = data->healPointMax;
}

void Construction::Attack(Entity* _target)
{
	_target->TakeDamage(data->damagePoint);
}
