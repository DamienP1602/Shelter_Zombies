#include "StandbyState.h"
#include "EntityBrain.h"
#include "Entity.h"
#include "Gameplay.h"

StandbyState::StandbyState(Brain* _brain) : State(_brain)
{
	BlackBoard* _blackboard = _brain->GetBlackBoard();

	standbyToChase = new StandbyToChase(_blackboard);
	standbyToAttack = new StandbyToAttack(_blackboard);
	standbyToDeath = new StandbyToDeath(_blackboard);
	transitions.push_back(standbyToChase);
	transitions.push_back(standbyToAttack);
	transitions.push_back(standbyToDeath);
}

StandbyState::~StandbyState()
{
	standbyToChase = nullptr;
	standbyToAttack = nullptr;
	standbyToDeath = nullptr;
	entity = nullptr;
	delete standbyToChase;
	delete standbyToAttack;
	delete standbyToDeath;
	delete entity;
}

void StandbyState::Init()
{
	standbyToAttack->Init(dynamic_cast<EntityBrain*>(brain)->GetAttackState());
	standbyToChase->Init(dynamic_cast<EntityBrain*>(brain)->GetChaseState());
	standbyToDeath->Init(dynamic_cast<EntityBrain*>(brain)->GetDeathState());
}

void StandbyState::Start()
{
	entity = dynamic_cast<Entity*>(brain->GetOwner());
	entity->GetComponent<AnimationComponent>()->RunAnimation("Idle", 1);
}

void StandbyState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
	if (entity->GetTarget() == nullptr || entity->GetTarget()->IsToRemove())
		Gameplay::GetInstance().SelectionTarget(entity, entity->IsAlly());
	brain->GetBlackBoard()->hasTarget = entity->GetTarget() && !entity->IsToRemove();
}

void StandbyState::Stop()
{
}