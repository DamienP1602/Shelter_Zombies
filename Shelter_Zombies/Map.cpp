#include "Map.h"
#include "Actor.h"
#include "CollectableActor.h"
#include "Macro.h"
#include "FileLoader.h"
#include "TextureManager.h"
#include "Game.h"
#include "Item.h"
#include "Enemy.h"
#include "Boss.h"
#include "Mob.h"
#include "InteractableActor.h"
#include "Game.h"


#define GRASS_PATH "grass.png"

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
	for (int _i = 0; _i < 30; _i++)
	{
		Row* _actualRow = new Row();
		for (int _j = 0; _j < 30; _j++)
		{
			const Vector2f& _position = Vector2f(50.0f * _i, 50.0f * _j);

			Tile* _tile = new Tile(new ShapeObject(ShapeData(_position, _tileSize, GRASS_PATH)), _tileSize);

			bool _specialColor = (_j + _i) % 2 == 0 ? true : false;
			if (_specialColor) _tile->visualTile->GetDrawable()->setFillColor(Color::Green);

			_actualRow->tiles.push_back(_tile);
		}
		allTiles.push_back(_actualRow);
	}

}