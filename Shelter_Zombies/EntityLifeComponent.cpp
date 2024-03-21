#include "EntityLifeComponent.h"
#include "Timer.h"
#include "ActorManager.h"

EntityLifeComponent::EntityLifeComponent(Actor* _owner, const int _maxLife) : Component(_owner)
{
	maxLife = _maxLife;
	currentLife = maxLife;
}

void EntityLifeComponent::TakeDamages(const int _damages)
{
	currentLife -= _damages;
	if (currentLife <= 0)
	{
		isDead = true;
		new Timer([&]() { Destroy(); }, seconds(0.1f), true, false);
	}
}

void EntityLifeComponent::Healing(const int _heal)
{
	currentLife + _heal > maxLife ? currentLife = maxLife : currentLife += _heal;
}

void EntityLifeComponent::Destroy()
{
	ActorManager::GetInstance().Remove(owner);
}
