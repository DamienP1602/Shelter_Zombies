#include "Entity.h"

Entity::Entity(string _name, const bool _isAlly, const ShapeData& _shape, const CollisionType& _activeCollision) :
	Actor(_name, _shape, CT_ENTITY, _activeCollision)
{
	layer = 2;
	brain = new EntityBrain(this);
	components.push_back(brain);
	movement = new EntityMovementComponent(this);
	components.push_back(movement);
	attack = new EntityAttackComponent(this);
	components.push_back(attack);
	life = new EntityLifeComponent(this);
	components.push_back(life);
	isAlly = _isAlly;

	SetActive(false);
	SetIsHidden(true);
}

Entity::~Entity()
{
	target = nullptr;
	data = nullptr;
	brain = nullptr;
	movement = nullptr;
	attack = nullptr;
	life = nullptr;
	delete data;
	delete target;
	delete brain;
	delete movement;
	delete attack;
	delete life;
}

void Entity::UpdateData()
{
	attack->SetData(data->damagePoint, data->cooldown, data->range);
	life->SetLife(data->maxLife);
	movement->SetData(data->speed, data->range);
}

void Entity::Init()
{
}
