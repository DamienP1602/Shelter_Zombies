#include "Construction.h"
#include "Entity.h"
#include "AllyConstructionManager.h"

Construction::Construction(const string& _name, const ShapeData& _shape, const bool _isAlly, Canvas* _canvas) :
	InteractableActor(_name, _shape, _canvas)
{
	layer = 1;
	isAlly = _isAlly;
	life = new EntityLifeComponent(this);
	attack = new EntityAttackComponent(this);
	components.push_back(life);

	Register();
}

Construction::~Construction()
{
	data = nullptr;
	life = nullptr;
	attack = nullptr;
	delete data;
	delete life;
	delete attack;
}

void Construction::Attack(Entity* _target)
{
}

void Construction::Register()
{
	AllyConstructionManager::GetInstance().Add(id, this);
}

void Construction::UpdateData()
{
	attack->SetData(data->damagePoint, data->cooldown, data->range);
	life->SetLife(data->maxLife);
}
