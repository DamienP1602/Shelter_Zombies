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
	if (!target)
		return true;
	return target->GetComponent<EntityLifeComponent>()->IsDead();
}

void EntityAttackComponent::Update(const float _deltaTime)
{
	CheckTargetInRange();
}

void EntityAttackComponent::CheckTargetInRange()
{
	if (!target)
		return;
	const Vector2f& _direction = target->GetShapePosition() - owner->GetShapePosition();
	const bool _hasHit = Raycast(owner->GetShapePosition(), _direction, range, hitInfo, { owner });
	isInRange = _hasHit && hitInfo.actor == target;
}

void EntityAttackComponent::Attack()
{	
	if (!isInRange || !target) 
		return;
	owner->GetComponent<AnimationComponent>()->RunAnimation("Attack", 1);
	target->GetComponent<EntityLifeComponent>()->TakeDamages(damages);
	cout << "ATTACK" << endl;
}

void EntityAttackComponent::StartAttack()
{
	cooldownTimer = new Timer([&]() { Attack(); }, seconds(cooldown), true, true);
}

void EntityAttackComponent::StopAttack()
{
	cooldownTimer->Stop();
	cooldownTimer = nullptr;
}