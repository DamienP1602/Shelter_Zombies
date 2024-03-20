#include "Map.h"
#include "Actor.h"
#include "CollectableActor.h"
#include "Macro.h"
#include "FileLoader.h"
#include "TextureManager.h"
#include "Game.h"
#include "Item.h"
#include "Enemy.h"
#include "InteractableActor.h"
#include "Game.h"

#define PATH_BENCH "Map/Bench.png"
#define PATH_STAND "/UIs/Shop/Stand.png"
#define PATH_PNJ "/Characters/PNJ/PNJA.png"
#define PATH_MERCHAND "/Characters/PNJ/Merchand.png"
#define PATH_DRAGON "Animations/dragon.png"
#define PATH_GRUB "/Animations/Grub.png"

Map::Map()
{

}

Map::~Map()
{
	for (Row* _row : allTiles)
	{
		for (Tile* _tile : _row->tiles)
		{
			delete _tile;
		}
	}
}

void Map::Init()
{
	const Vector2f& _tileSize = Vector2f(50.0f, 50.0f);
	for (int _i = 0; _i < 50; _i++)
	{
		Row* _actualRow = new Row();
		for (int _j = 0; _j < 50; _j++)
		{
			const Vector2f& _position = Vector2f(50.0f * _i, 50.0f * _j);
			const string& _path = (_j + _i) % 2 == 0 ? "yellow.png" : "blue.png";
			_actualRow->tiles.push_back(new Tile(new ShapeObject(ShapeData(_position, _tileSize, _path)),_tileSize));
		}
		allTiles.push_back(_actualRow);
	}

}