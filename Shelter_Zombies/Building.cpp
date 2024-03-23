#include "Building.h"

Building::Building(const string& _name, const ShapeData& _shape, const bool _isAlly, Canvas* _canvas) :
	InteractableActor(_name, _shape, _canvas)
{
	layer = 1;
	life = new EntityLifeComponent(this);
	isAlly = _isAlly;
}

Building::~Building()
{
	life = nullptr;
	data = nullptr;
	delete data;
	delete life;
}
