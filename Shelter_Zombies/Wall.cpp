#include "Wall.h"

#define CONSTRUCTION_SHAPE_WALL_PATH ""
#define CONSTRUCTION_SHAPE_WALL_SIZE Vector2f()

Wall::Wall(const Vector2f& _position):
	Construction("Wall", ShapeData(_position, CONSTRUCTION_SHAPE_WALL_SIZE, CONSTRUCTION_SHAPE_WALL_PATH))
{
	data = new ConstructionData(10, 0, 0);
}
