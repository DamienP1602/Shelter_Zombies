#include "EntityMovementComponent.h"
#include "AnimationComponent.h"
#include "Actor.h"
#include "Kismet.h"

EntityMovementComponent::EntityMovementComponent(Actor* _owner, const float _speed) : Component(_owner)
{
	speed = _speed;
	minRange = 1; //TODO check
	collision = owner->GetComponent<CollisionComponent>();
	animation = owner->GetComponent<AnimationComponent>();
}

EntityMovementComponent::~EntityMovementComponent()
{
	animation = nullptr;
	collision = nullptr;
	delete animation;
	delete collision;
}

void EntityMovementComponent::SetDestination(const Vector2f& _destination, const bool _canMove)
{
	destination = _destination;
	canMove = _canMove;

	//Vector2f _newDirection = _destination - owner->GetShapePosition();
	//Normalize(_newDirection);
	//if (_newDirection.x != lastDirection.x)
	//{
	//	canMove = false;
	//	owner->GetComponent<AnimationComponent>()->RunAnimation("Turn", lastDirection.x);
	//	owner->GetComponent<AnimationComponent>()->GetCurrentAnimation()->SetDirectionX(_newDirection.x);
	//	new Timer([&]()
	//		{
	//			SetCanMove(true);
	//		}, seconds(0.75f), true, false);
	//}
	//else
	//{
	//	owner->GetComponent<AnimationComponent>()->RunAnimation("Running", lastDirection.x);
	//}
}

void EntityMovementComponent::Update(const float _deltaTime)
{
	//if (!canMove)
	//{
	//	animation->RunAnimation("Idle", lastDirection.x);
	//}
	MoveToDestination(_deltaTime);
}

void EntityMovementComponent::MoveToDestination(const float _deltaTime)
{
	if (!canMove) 
		return;
	if (IsAtPosition())
	{
		canMove = false;
		return;
	}

	Shape* _shape = owner->GetDrawable();
	Vector2f _direction = destination - _shape->getPosition();
	Normalize(_direction);
	lastDirection = _direction;

	const Vector2f& _position = _shape->getPosition() + _direction * speed * _deltaTime;
	_shape->setPosition(_position);
}

bool EntityMovementComponent::IsAtPosition() const
{
	return Distance(owner->GetShapePosition(), destination) <= minRange;
}
