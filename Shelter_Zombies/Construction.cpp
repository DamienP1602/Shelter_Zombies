#include "Construction.h"
#include "Entity.h"
#include "AllyConstructionManager.h"

Construction::Construction(const string& _name, const ShapeData& _shape, const bool _isAlly, Canvas* _canvas) :
	InteractableActor(_name, _shape, _canvas)
{
	layer = 1;
	life = new EntityLifeComponent(this);
	isAlly = _isAlly;

	Register();
}

Construction::~Construction()
{
	data = nullptr;
	life = nullptr;
	delete data;
	delete life;
}

void Construction::Attack(Entity* _target)
{
}

void Construction::Register()
{
	AllyConstructionManager::GetInstance().Add(id, this);
}
