#include "DeathState.h"
#include "Brain.h"
#include "EntityMovementComponent.h"
#include "Actor.h"

DeathState::DeathState(Brain* _brain) : State(_brain)
{

}

void DeathState::Start()
{
	Actor* _owner = brain->GetOwner();
	movement = _owner->GetComponent<EntityMovementComponent>();
	_owner->GetComponent<AnimationComponent>()->RunAnimation("Death", 1);
	cout << "Death" << endl;
}

void DeathState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
}

void DeathState::Stop()
{
}

void DeathState::Init() // besoin de garder vide
{
}
