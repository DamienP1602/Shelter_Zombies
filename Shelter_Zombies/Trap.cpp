#include "Trap.h"

#define CONSTRUCTION_SHAPE_TRAP_PATH "GPE/Construction/Trap_1.png"
#define CONSTRUCTION_SHAPE_TRAP_SIZE Vector2f(100,100)

Trap::Trap(const Vector2f& _position) :
	Construction("Trap", ShapeData(_position, CONSTRUCTION_SHAPE_TRAP_SIZE, CONSTRUCTION_SHAPE_TRAP_PATH))
{
	data = new ConstructionData(10, 10, 0,20);
}
