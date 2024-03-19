#include "Decor.h"

Decor::Decor(const ShapeData& _shape) :
	Actor("Decor", _shape, CT_BLOCK)
{
	layer = 0;
}

Decor::~Decor()
{
}
