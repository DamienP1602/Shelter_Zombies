#include "Fighter.h"

#define ENTITY_SHAPE_FIGHTER_PATH ""
#define ENTITY_SHAPE_FIGHTER_SIZE Vector2f(50.0f,50.0f)

Fighter::Fighter(const Vector2f& _position) : 
	Entity("Fighter", ShapeData(_position, ENTITY_SHAPE_FIGHTER_SIZE, ENTITY_SHAPE_FIGHTER_PATH))
{
	data = new EntityData(10, 4, 3, 1, 0);
	
	GetComponent<CollisionComponent>()->SetTypeOfCollision(CT_ENNEMY);
}

void Fighter::Movement()
{

}

void Fighter::Action()
{
	target->TakeDamage(data->damagePoint);
}
