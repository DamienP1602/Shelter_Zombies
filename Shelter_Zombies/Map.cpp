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
			SetOriginAtMiddle(_tile->visualTile->GetDrawable());			

			_actualRow->tiles.push_back(_tile);
		}
		allTiles.push_back(_actualRow);
	}

}

void Map::Load()
{
	//TODO LOAD
}
bool Map::PutInMap(InteractableActor* _actor,const Vector2f& _mousePosition)
{
	for (Row* _row : allTiles)
	{
		for (Tile* _tile : _row->tiles)
		{
			if (_tile->visualTile->GetDrawable()->getGlobalBounds().contains(_mousePosition))
			{
				if (!_tile->actorOnTile)
				{
					_tile->actorOnTile = _actor;
					_tile->actorOnTile->GetDrawable()->setPosition(_tile->visualTile->GetShapePosition());
					return true;
				}
				else return false;
			}
		}
	}
	return false;
}
