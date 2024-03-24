#include "EntityLifeComponent.h"
#include "Timer.h"
#include "ActorManager.h"

EntityLifeComponent::EntityLifeComponent(Actor* _owner) : Component(_owner)
{
	maxLife = 10;
	currentLife = maxLife;
	isDead = false;
}

bool EntityLifeComponent::TakeDamages(const int _damages)
{
	currentLife -= _damages;
	if (currentLife <= 0)
	{
		isDead = true;
		owner->GetComponent<AnimationComponent>()->RunAnimation("Death", 1);
		return true;
	}
	return false;
}

void EntityLifeComponent::Healing(const int _heal)
{
	currentLife + _heal > maxLife ? currentLife = maxLife : currentLife += _heal;
}

void EntityLifeComponent::Destroy()
{
	ActorManager::GetInstance().Remove(owner);
}
