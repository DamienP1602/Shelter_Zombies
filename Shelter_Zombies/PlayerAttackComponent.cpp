#include "PlayerAttackComponent.h"
#include "Game.h"
#include "Enemy.h"
#include "Macro.h"
#include"Game.h"
#include "Kismet.h"

PlayerAttackComponent::PlayerAttackComponent(Actor* _owner, const int _damages, const float _range) : EntityAttackComponent(_owner)
{
	animation = owner->GetComponent<PlayerAnimationComponent>();
	SetData(_damages, 1.0f, _range);
	StartAttack();
}

PlayerAttackComponent::~PlayerAttackComponent()
{
	animation = nullptr;
	delete animation;
}

void PlayerAttackComponent::Update(const float _deltaTime)
{
	const Vector2f& _origin = owner->GetDrawable()->getPosition();
	const float _radius = static_cast<Player*>(owner)->GetData()->range;
	Actor* _target = nullptr;
	bool _isInRange = false;

	CircleCast(_origin, _radius, _target, _isInRange, { owner });

	SetTarget(_target);
	SetInRange(_isInRange);

}
