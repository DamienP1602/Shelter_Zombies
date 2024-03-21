#include "Turret.h"

#define CONSTRUCTION_SHAPE_TURRET_PATH "GPE/Construction/Canon_1.png"
#define CONSTRUCTION_SHAPE_TURRET_SIZE Vector2f(100,100)

Turret::Turret(const Vector2f& _position) :
	Construction("Turret", ShapeData(_position, CONSTRUCTION_SHAPE_TURRET_SIZE, CONSTRUCTION_SHAPE_TURRET_PATH))
{
	data = new ConstructionData(6, 3, 0,30);
}
