#include "PlayerMovementComponent.h"
#include "Actor.h"
#include "PlayerAnimationComponent.h"
#include "Game.h"
#include "Timer.h"
#include "Macro.h"
#include "Kismet.h"
#include "FxManager.h"

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner) : Component(_owner)
{
	// Movement
	canMove = true;
	speed = 0.45f;
	directionHasChanged = false;
	direction = Vector2f();

	//Distance
	checkWallDistance = owner->GetShapeSize().x / 2.0f;

	// Components
	animation = owner->GetComponent<PlayerAnimationComponent>();
	collision = owner->GetComponent<CollisionComponent>();
}

void PlayerMovementComponent::Update(const float _deltaTime)
{
	if (!canMove) return;

	Vector2f _offset = direction * speed * _deltaTime;

	const Vector2f& _collisionOffset = Vector2f(0.0f, 0.0f);
	const Vector2f& _destination = _offset + _collisionOffset;
	collision->GetBoxCollision()->GetDrawable()->setPosition(owner->GetShapePosition() + Vector2f(_destination.x * checkWallDistance, _destination.y));

	if (!collision->CheckCollision())
	{
		owner->GetDrawable()->move(_offset);
	}
}

void PlayerMovementComponent::SetDirectionX(const float _directionX, const string& _animName)
{
	if (!canMove) return;

	if (_directionX == direction.x * -1.0f)
	{
		directionHasChanged = true;
	}

	if (_directionX == 0.0f)
	{
		animation->GetCurrentAnimation()->RunAnimation("StopRight", dashDirection);

		if (directionHasChanged)
		{
			directionHasChanged = false;
			return;
		}

		if (owner->GetDrawable()->getScale().x >= 0.0f)
		{
			dashDirection = 1.0f;
		}

		else
		{
			dashDirection = -1.0f;
		}
	}

	else
	{
		dashDirection = _directionX;
		animation->GetCurrentAnimation()->RunAnimation(_animName, dashDirection);
	}

	direction.x = _directionX;
}