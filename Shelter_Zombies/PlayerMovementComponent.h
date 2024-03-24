#pragma once
#include "Component.h"
#include "PlayerAnimationComponent.h"
#include "SoundManager.h"
#include "CollisionComponent.h"

class PlayerMovementComponent : public Component
{
	// Movement
	bool canMove = false;
	float speed = 0.45f;
	bool directionHasChanged;
	Vector2f direction;

	// Ground
	bool isOnGround;
	float checkGroundDistance;

	// Jump
	bool isJumping;
	bool canDoubleJump;
	float jumpForce;
	float currentJumpForce;
	float jumpFactor;

	// Gravity
	float gravity;
	float downSpeed;
	float downFactor;

	// Dash
	bool canDash;
	bool isDashing;
	bool isResetingDash;
	float dashSpeed;
	float dashDuration;
	float dashCooldown;
	float dashDirection;

	// Sit
	bool isStanding;
	float sitOffset;

	//Distance
	float checkWallDistance;

	// Components
	PlayerAnimationComponent* animation;
	CollisionComponent* collision;

public:
	void SetDirectionX(const float _directionX, const string& _animName);
	void SetDirectionY(const float _directionY)
	{
		if (!canMove) return;
		direction.y = _directionY;
	}
	bool IsOnGround() const
	{
		return isOnGround;
	}
	bool GetIsDashing() const
	{
		return isDashing;
	}
	bool IsStanding() const
	{
		return isStanding;
	}
	Vector2f GetDirection() const
	{
		return direction;
	}
	float GetDashDirection()const
	{
		return dashDirection;
	}

public:
	PlayerMovementComponent(Actor* _owner);
	~PlayerMovementComponent();

public:
	virtual void Update(const float _deltaTime) override;
};