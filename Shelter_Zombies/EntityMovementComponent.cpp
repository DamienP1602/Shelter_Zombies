#include "EntityMovementComponent.h"
#include "AnimationComponent.h"
#include "Actor.h"
#include "Kismet.h"

EntityMovementComponent::EntityMovementComponent(Actor* _owner) : Component(_owner)
{
	string _name = _owner->GetID();
	target = nullptr;
	canMove = false;
	speed = 1;
	minRange = 1;
	animation = owner->GetComponent<AnimationComponent>();
	collision = owner->GetComponent<CollisionComponent>();
}

EntityMovementComponent::~EntityMovementComponent()
{
	animation = nullptr;
	collision = nullptr;
	delete animation;
	delete collision;
}

void EntityMovementComponent::SetTarget(Actor* _target, const bool _canMove)
{
	target = _target;
	canMove = _canMove;
	animation->RunAnimation("Movement", lastDirection.x);
}

void EntityMovementComponent::Update(const float _deltaTime)
{
	//if (!canMove)
	//	animation->RunAnimation("Idle", lastDirection.x);
	SetDestination();
	canMove = !IsAtPosition();
	MoveToDestination(_deltaTime);
}

void EntityMovementComponent::SetDestination()
{
	if (!target)
		destination = owner->GetShapePosition();
	else
		destination = target->GetShapePosition();
}

void EntityMovementComponent::MoveToDestination(const float _deltaTime)
{
	if (!canMove) 
		return;

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
