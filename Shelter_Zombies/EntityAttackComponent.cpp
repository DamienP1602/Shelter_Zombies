#include "EntityAttackComponent.h"
#include "Actor.h"
#include "Kismet.h"
#include "EntityLifeComponent.h"
#include "io.h"
#include "TimerManager.h"

EntityAttackComponent::EntityAttackComponent(Actor* _owner) : Component(_owner)
{
	damages = 1;
	cooldown = 1;
	range = 1;
	isInRange = false;
	hitInfo = HitInfo();
	cooldownTimer = nullptr;
}

EntityAttackComponent::~EntityAttackComponent()
{
	StopAttack();
	target = nullptr;
	delete cooldownTimer;
	delete target;
}

bool EntityAttackComponent::IsTargetDead() const
{
	if (!target) return true;

	if (target->IsToRemove())
		return true;
	return target->GetComponent<EntityLifeComponent>()->IsDead();
}

void EntityAttackComponent::Update(const float _deltaTime)
{
	CheckTargetInRange();
}

void EntityAttackComponent::CheckTargetInRange()
{
	if (!target || target->IsToRemove())
		return;
	isInRange = Distance(owner->GetShapePosition(), target->GetShapePosition()) <= range;
}

void EntityAttackComponent::Attack()
{
	if (!target || !isInRange)
		return;
	owner->GetComponent<AnimationComponent>()->RunAnimation("Attack", 1);
	if (target->GetComponent<EntityLifeComponent>()->TakeDamages(damages))
	{
		target->GetComponent<EntityAttackComponent>()->StopAttack();
		ActorManager::GetInstance().Remove(target);
		target = nullptr;
	}
}

void EntityAttackComponent::StartAttack()
{
	Attack();
	cooldownTimer = new Timer([&]() { Attack(); }, seconds(cooldown), true, true);
}

void EntityAttackComponent::StopAttack()
{
	cooldownTimer->Stop();
	TimerManager::GetInstance().Remove(cooldownTimer);
	cooldownTimer = nullptr;
}