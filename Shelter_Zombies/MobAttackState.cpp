#include "MobAttackState.h"
#include "MobBrain.h"
#include "Game.h"

MobAttackState::MobAttackState(Brain* _brain) : AttackState(_brain)
{
}


void MobAttackState::Init()
{
	//attackToDeath->Init(dynamic_cast<MobBrain*>(brain)->GetDeathState());
}

void MobAttackState::Start()
{
	AttackState::Start();

	animation->RunAnimation("Attack", animation->GetCurrentAnimation()->GetDirectionX());

	//Game::GetPlayer()->GetStats()->UpdateLife(-1);

	//new Timer([&]() {
	//	brain->GetBlackBoard()->isInRange = false;
	//}, seconds(0.12f), true, false);
}