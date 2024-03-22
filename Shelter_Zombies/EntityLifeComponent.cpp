#include "EntityLifeComponent.h"
#include "Timer.h"
#include "ActorManager.h"

EntityLifeComponent::EntityLifeComponent(Actor* _owner) : Component(_owner)
{
	maxLife = 10;
	currentLife = maxLife;
}

void EntityLifeComponent::TakeDamages(const int _damages)
{
	currentLife -= _damages;
	if (currentLife <= 0)
	{
		isDead = true;
		owner->GetComponent<AnimationComponent>()->RunAnimation("Death", 1);
		new Timer([&]() { Destroy(); }, seconds(0.5f), true, false);
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
