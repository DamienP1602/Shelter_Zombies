#include "ChaseState.h"
#include "EntityMovementComponent.h"
#include "EntityBrain.h"
#include "Entity.h"

ChaseState::ChaseState(Brain* _brain) : State(_brain)
{
	BlackBoard* _blackboard = _brain->GetBlackBoard();
	
	chaseToAttack = new ChaseToAttack(_blackboard);
	chaseToDeath = new ChaseToDeath(_blackboard);
	transitions.push_back(chaseToAttack);
	transitions.push_back(chaseToDeath);
}

ChaseState::~ChaseState()
{
	chaseToAttack = nullptr;
	chaseToAttack = nullptr;
	movement = nullptr;
	delete chaseToAttack;
	delete chaseToAttack;
	delete movement;
}

void ChaseState::Init()
{
	chaseToAttack->Init(dynamic_cast<EntityBrain*>(brain)->GetAttackState());
	chaseToDeath->Init(dynamic_cast<EntityBrain*>(brain)->GetDeathState());
}

void ChaseState::Start()
{
	Actor* _owner = brain->GetOwner();
	movement = _owner->GetComponent<EntityMovementComponent>();
	movement->SetCanMove(true);
	_owner->GetComponent<AnimationComponent>()->RunAnimation("Movement", 1);
}

void ChaseState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
	brain->GetBlackBoard()->isInRange = movement->IsAtPosition();
	brain->GetBlackBoard()->isDead = dynamic_cast<Entity*>(brain->GetOwner())->IsDead();
}

void ChaseState::Stop()
{	
	movement->SetCanMove(false);
}