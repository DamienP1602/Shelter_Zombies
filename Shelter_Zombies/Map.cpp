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

Map::Map(const string& _name)
{
	name = _name;
	allTiles = vector<Row*>();
	borders = new Borders();

	Init();
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

	/*for (ShapeObject* _shape : borders->shapes)
	{
		delete _shape;
	}*/
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


	const Vector2f& _upBorderPosition = Vector2f();
}

void Map::Load()
{
	for (Row* _row : allTiles)
	{
		for (Tile* _tile : _row->tiles)
		{
			if (_tile->actorOnTile)
			{
				_tile->actorOnTile->SetIsHidden(false);
			}
			_tile->visualTile->SetIsHidden(false);
		}
	}
}

void Map::DeLoad()
{
	for (Row* _row : allTiles)
	{
		for (Tile* _tile : _row->tiles)
		{
			if (_tile->actorOnTile)
			{
				_tile->actorOnTile->SetIsHidden(true);
			}

			_tile->visualTile->SetIsHidden(true);
		}
	}
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

bool Map::PutInMap(InteractableActor* _actor, const Vector2i& _gridPosition)
{
	for (int _i = 0; _i < SIZE(allTiles); _i++)
	{
		for (int _j = 0; _j < SIZE(allTiles[_i]->tiles); _j++)
		{
			if (_i == _gridPosition.x && _j == _gridPosition.y)
			{
				if (!allTiles[_i]->tiles[_j]->actorOnTile)
				{
					allTiles[_i]->tiles[_j]->actorOnTile = _actor;
					allTiles[_i]->tiles[_j]->actorOnTile->GetDrawable()->setPosition(allTiles[_i]->tiles[_j]->visualTile->GetShapePosition());
					return true;
				}
				else return false;

			}
		}
	}
	return false;
}
