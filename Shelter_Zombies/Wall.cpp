#include "Wall.h"

Wall::Wall(const Vector2f& _position,const int _level):
	Construction("Wall", ShapeData(_position, Vector2f(50.0f,50.0f), ""))
{
	data = new ConstructionData(10, 0, _level,5);
}
