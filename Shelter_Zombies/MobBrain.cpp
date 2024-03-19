#include "MobBrain.h"

MobBrain::MobBrain(Actor* _owner) : EnemyBrain(_owner)
{
	attack = new MobAttackState(this);
	states.push_back(attack);

	Init();
}


void MobBrain::Init()
{
	attack->Init();
	death->Init();

	currentState->Start();
}