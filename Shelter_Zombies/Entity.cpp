#include "Entity.h"

Entity::Entity(string _name, const ShapeData& _shape):
	Actor(_name, _shape, CT_BLOCK)
{
	layer = 2;
	brain = new EntityBrain(this);
	movement = new EntityMovementComponent(this, 1);
	attack = new EntityAttackComponent(this, 1, 1, 1);
	life = new EntityLifeComponent(this, 1);
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
	movement->SetSpeed(data->speed);
}
