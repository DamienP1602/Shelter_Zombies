#include "EntityAttackComponent.h"
#include "Actor.h"
#include "Kismet.h"
#include "EntityLifeComponent.h"
#include "io.h"

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
	//TODO pk erreur ????
	if (!target || target->IsToRemove() || !isInRange)
		return;
	owner->GetComponent<AnimationComponent>()->RunAnimation("Attack", 1);
	target->GetComponent<EntityLifeComponent>()->TakeDamages(damages);
}

void EntityAttackComponent::StartAttack()
{
	Attack();
	cooldownTimer = new Timer([&]() { Attack(); }, seconds(cooldown), true, true);
}

void EntityAttackComponent::StopAttack()
{
	cooldownTimer->Stop();
	cooldownTimer = nullptr;
}