#include "Church.h"
#include "EntityBrain.h"
#include "AllyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SUPPORT_PATH "Entities/Church_0.png"
#define ENTITY_SHAPE_SUPPORT_SIZE Vector2f(100,100)

Church::Church(const Vector2f& _position, const int _level) :
	Entity("Church", ShapeData(_position, ENTITY_SHAPE_SUPPORT_SIZE, ENTITY_SHAPE_SUPPORT_PATH))
{
	data = new EntityData(6, -3, 4, 8, 2, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Church::~Church()
{
	AllyEntityManager::GetInstance().Remove(this);
	ActorManager::GetInstance().Remove(this);
}
