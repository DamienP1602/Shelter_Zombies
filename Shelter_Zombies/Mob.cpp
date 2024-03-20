#include "Mob.h"
#include "Macro.h"
#include "EntityMovementComponent.h"
#include "MobBrain.h"

Mob::Mob(const ShapeData& _data) : Enemy(STRING_ID("Mob"), _data)
{
	isPatrolling = false;
	cooldownAttack = false;

	/*movement = new MobMovementComponent(this);
	components.push_back(movement);*/

	life = new EntityLifeComponent(this, 1);
	components.push_back(life);

	sight = new SightComponent(this, 100.0f);
	components.push_back(sight);

	attack = new EntityAttackComponent(this, 1, 2, 8);
	components.push_back(attack);

	brain = new MobBrain(this);
	components.push_back(brain);
}

void Mob::Update(const float _deltaTime)
{
	Enemy::Update(_deltaTime);
}

void Mob::Death()
{
	//ActorManager::GetInstance().Remove("Mob");
	cout << "il est mort " << endl;
}

void Mob::Attack(Player* _player)
{

}