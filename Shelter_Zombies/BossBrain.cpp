#include "BossBrain.h"

BossBrain::BossBrain(Actor* _owner) : EnemyBrain(_owner)
{
	chase = new ChaseState(this);
	states.push_back(chase);

	attack = new BossAttackState(this);
	states.push_back(attack);

	Init();
}

BossBrain::~BossBrain()
{
	delete chase;
	delete attack;
}

void BossBrain::Init()
{
	chase->Init();
	attack->Init();
	
	currentState->Start();
}