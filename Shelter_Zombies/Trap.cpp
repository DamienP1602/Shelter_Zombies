#include "Trap.h"

#define CONSTRUCTION_SHAPE_TRAP_PATH ""
#define CONSTRUCTION_SHAPE_TRAP_SIZE Vector2f()

Trap::Trap(const Vector2f& _position) :
	Construction("Trap", ShapeData(_position, CONSTRUCTION_SHAPE_TRAP_SIZE, CONSTRUCTION_SHAPE_TRAP_PATH))
{
	data = new ConstructionData(10, 10, 0);
}
