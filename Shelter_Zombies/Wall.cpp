#include "Wall.h"
#include "Macro.h"


#define CONSTRUCTION_SHAPE_WALL_PATH "GPE/Construction/Wall.png"
#define CONSTRUCTION_SHAPE_WALL_SIZE Vector2f(100,100)

Wall::Wall(const Vector2f& _position,const int _level,const bool _isAlly):
	Construction(STRING_ID("Wall"), ShapeData(_position, Vector2f(50.0f,50.0f), ""),_isAlly)
{
	data = new ConstructionData(10, 0, _level,5);
}
