#include "Entity.h"

Entity::Entity(string _name, const bool _isAlly, const ShapeData& _shape):
	Actor(_name, _shape, CT_ENTITY)
{
	layer = 2;
	brain = new EntityBrain(this);
	movement = new EntityMovementComponent(this);
	components.push_back(movement);
	attack = new EntityAttackComponent(this);
	components.push_back(attack);
	life = new EntityLifeComponent(this);
	components.push_back(life);
	isAlly = _isAlly;

	isAlly = _isAlly;

	SetActive(false);
	SetIsHidden(true);
}

Entity::~Entity()
{	
	target = nullptr;
	data = nullptr;
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
