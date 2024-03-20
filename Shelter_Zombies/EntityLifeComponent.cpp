#include "EntityLifeComponent.h"

EntityLifeComponent::EntityLifeComponent(Actor* _owner, const int _maxLife) : Component(_owner)
{
	maxLife = _maxLife;
	isDead = false;
}

void EntityLifeComponent::TakeDamages(const int _damages)
{
	currentLife -= _damages;
	if (currentLife <= 0)
		isDead = true;
}

void EntityLifeComponent::Healing(const int _heal)
{
	currentLife + _heal > maxLife ? currentLife = maxLife : currentLife += _heal;
}
