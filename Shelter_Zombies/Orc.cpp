#include "Orc.h"
#include "EntityBrain.h"
#include "EnemyEntityManager.h"
#include "ActorManager.h"

#define ENTITY_SHAPE_SHOOTER_PATH "Entities/Orc_0.png"
#define ENTITY_SHAPE_SHOOTER_SIZE Vector2f(75.f,75.f)

Orc::Orc(const Vector2f& _position, const int _level) :
	Entity("Orc", ShapeData(_position, ENTITY_SHAPE_SHOOTER_SIZE, ENTITY_SHAPE_SHOOTER_PATH))
{
	data = new EntityData(5, 2, 2, .3f, 400, _level);
	brain = new EntityBrain(this);
	UpdateData();
}

Orc::~Orc()
{
	EnemyEntityManager::GetInstance().Remove(this);
}

