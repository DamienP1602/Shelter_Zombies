#include "AttackState.h"
#include "EntityBrain.h"

AttackState::AttackState(Brain* _brain) : State(_brain)
{
	attackToStandby = new AttackToStandby(_brain->GetBlackBoard());
	attackToChase = new AttackToChase(_brain->GetBlackBoard());
	transitions.push_back(attackToStandby);
	transitions.push_back(attackToChase);
}

AttackState::~AttackState()
{
	attackToStandby = nullptr;
	attackToChase = nullptr;
	attack = nullptr;
	delete attackToStandby;
	delete attackToChase;
	delete attack;
}

void AttackState::Start()
{
	Actor* _owner = brain->GetOwner();
	attack = _owner->GetComponent<EntityAttackComponent>();
	attack->StartAttack();
}

void AttackState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
	brain->GetBlackBoard()->hasTarget = attack->IsTargetDead();
}

void AttackState::Stop()
{
	//animation->RunAnimation("Idle", animation->GetCurrentAnimation()->GetDirectionX());
	attack->StopAttack();
}

void AttackState::Init()
{
	attackToChase->Init(dynamic_cast<EntityBrain*>(brain)->GetChaseState());
	attackToStandby->Init(dynamic_cast<EntityBrain*>(brain)->GetStanbyState());
}
