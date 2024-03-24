#include "PlayerAnimationComponent.h"

PlayerAnimationComponent::PlayerAnimationComponent(Actor* _owner) : Component(_owner)
{
	animation = new AnimationComponent(_owner);
	animPlayer = vector<string>();
}

PlayerAnimationComponent::~PlayerAnimationComponent()
{
	animation = nullptr;
	delete animation;
}

void PlayerAnimationComponent::Init()
{
	animPlayer.push_back("Idle");
	animPlayer.push_back("RunRight");
	animPlayer.push_back("RunLeft");
	animPlayer.push_back("Death");
	animPlayer.push_back("Attack");

	const Vector2f& _size = Vector2f(120.0f, 80.0f);
	const float _speed = 0.1f;

	animation->InitAnimations({
		AnimationData("Idle", Vector2f(0.0f, 80.0f), _size, READ_RIGHT, true, 10, _speed),
		AnimationData("RunRight", Vector2f(0.0f, 160.0f), _size, READ_RIGHT, true, 10, _speed),
		AnimationData("RunLeft", Vector2f(0.0f, 160.0f), _size, READ_RIGHT, true, 10, _speed),
		AnimationData("Death", Vector2f(0.0f, 0.0f), _size, READ_RIGHT, true, 10, _speed),
		AnimationData("Attack", Vector2f(0.0f, 240.0f), _size, READ_RIGHT, false, 4, _speed,"Idle")
	});
}