#pragma once
#include "Component.h"
#include "CollisionComponent.h"
#include "AnimationComponent.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

using namespace std;
using namespace sf;

class EntityMovementComponent : public Component
{
protected:
	bool canMove;
	Vector2f lastDirection;
	float speed;
	float minRange;
	Vector2f destination;

	AnimationComponent* animation = nullptr;
	CollisionComponent* collision = nullptr;

public:
	EntityMovementComponent(Actor* _owner, const float _speed);
	~EntityMovementComponent();

	void SetSpeed(const float _speed)
	{
		speed = _speed;
	}
	void SetCanMove(const bool _status)
	{
		canMove = _status;
	}
	void SetDestination(const Vector2f& _destination, const bool _canMove = true);

	Vector2f GetDestination() const
	{
		return destination;
	}
	bool CanMove() const
	{
		return canMove;
	}
	Vector2f GetLastDirection() const
	{
		return lastDirection;
	}

	virtual void Update(const float _deltaTime) override;
	void MoveToDestination(const float _deltaTime);
	bool IsAtPosition() const;
};