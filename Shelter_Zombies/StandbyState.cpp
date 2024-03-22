#include "StandbyState.h"
#include "EntityBrain.h"
#include "Entity.h"

StandbyState::StandbyState(Brain* _brain) : State(_brain)
{
	BlackBoard* _blackboard = _brain->GetBlackBoard();

	standbyToChase = new StandbyToChase(_blackboard);
	standbyToDeath = new StandbyToDeath(_blackboard);
	transitions.push_back(standbyToChase);
	transitions.push_back(standbyToDeath);
}

StandbyState::~StandbyState()
{
	standbyToChase = nullptr;
	standbyToDeath = nullptr;
	entity = nullptr;
	delete standbyToChase;
	delete standbyToDeath;
	delete entity;
}

void StandbyState::Init()
{
	standbyToChase->Init(dynamic_cast<EntityBrain*>(brain)->GetChaseState());
	standbyToDeath->Init(dynamic_cast<EntityBrain*>(brain)->GetDeathState());
}

void StandbyState::Start()
{
	Actor* _owner = brain->GetOwner();
	_owner->GetComponent<AnimationComponent>()->RunAnimation("Idle", 1);
	entity = dynamic_cast<Entity*>(brain->GetOwner());
}

void StandbyState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
	brain->GetBlackBoard()->hasTarget = entity->GetTarget();
}

void StandbyState::Stop()
{
}