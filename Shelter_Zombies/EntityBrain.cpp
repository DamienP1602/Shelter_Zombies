#include "EntityBrain.h"

EntityBrain::EntityBrain(Actor* _owner) : Brain(_owner)
{
	standby = new StandbyState(this);
	chase = new ChaseState(this);
	attack = new AttackState(this);
	death = new DeathState(this);

	states.push_back(standby);
	states.push_back(chase);
	states.push_back(attack);
	states.push_back(death);

	Init();
}

EntityBrain::~EntityBrain()
{
	standby = nullptr;
	chase = nullptr;
	attack = nullptr;
	death = nullptr;
	delete standby;
	delete chase;
	delete attack;
	delete death;
}

void EntityBrain::Init()
{
	standby->Init();
	chase->Init();
	attack->Init();
	death->Init();

	currentState->Start();
}
