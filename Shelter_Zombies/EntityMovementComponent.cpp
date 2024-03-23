#include "EntityMovementComponent.h"
#include "AnimationComponent.h"
#include "Actor.h"
#include "Kismet.h"

EntityMovementComponent::EntityMovementComponent(Actor* _owner) : Component(_owner)
{
	string _name = _owner->GetID();
	target = nullptr;
	canMove = false;
	lastDirection = Vector2f(1.0f, 1.0f);
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
}

void EntityMovementComponent::Update(const float _deltaTime)
{
	SetDestination();
	canMove = !IsAtPosition();
	MoveToDestination(_deltaTime);
}

void EntityMovementComponent::SetDestination()
{
	if (!target || target->IsToRemove())
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
