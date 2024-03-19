#include "Entity.h"

Entity::Entity(string _name, const ShapeData& _shape):
	Actor(_name, _shape, CT_BLOCK)
{
	layer = 2;
	isDead = false;
}

Entity::~Entity()
{
	target = nullptr;
	data = nullptr;
}

void Entity::TakeDamage(int _damage)
{
	data->currentHP -= _damage;
	if (data->currentHP <= 0)
		isDead = false;
}

void Entity::Healing(int _heal)
{
	data->currentHP + _heal > data->healPointMax ? data->currentHP = data->healPointMax : data->currentHP += _heal;
}

void Entity::Action()
{
	if (!target)
		return;
}
