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
	float speed;
	float minRange;
	Actor* target;
	Vector2f destination;
	Vector2f lastDirection;

	AnimationComponent* animation = nullptr;
	CollisionComponent* collision = nullptr;

public:
	EntityMovementComponent(Actor* _owner);
	~EntityMovementComponent();

	void SetData(const float _speed, const float _range)
	{
		speed = _speed;
		minRange = _range;
	}
	void SetCanMove(const bool _status)
	{
		canMove = _status;
	}
	void SetTarget(Actor* _target, const bool _canMove = true);

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
	void SetDestination();
	void MoveToDestination(const float _deltaTime);
	bool IsAtPosition() const;
};