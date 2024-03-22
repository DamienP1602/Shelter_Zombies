#include "Decor.h"

Decor::Decor(const ShapeData& _shape) :
	Actor("Decor", _shape, CT_WALL)
{
	layer = 0;
}

Decor::~Decor()
{
}
