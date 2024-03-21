#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeObject.h"
#include "InteractableActor.h"
#include"PNJ.h"
#include "CollectableActor.h"

using namespace std;
using namespace sf;

struct Tile
{
	ShapeObject* visualTile;
	Vector2f size;
	Vector2f position;
	InteractableActor* actorOnTile;

	Tile()
	{
		visualTile = nullptr;
		size = Vector2f();
		position = Vector2f();
		actorOnTile = nullptr;
	}
	Tile(ShapeObject* _visualTile,const Vector2f& _size)
	{
		visualTile = _visualTile;
		size = _size;
		position = _visualTile->GetShapePosition();
		actorOnTile = nullptr;
	}
};

struct Row
{
	vector<Tile*> tiles;

	Row()
	{
		tiles = vector<Tile*>();
	}
};

struct Borders
{
	vector<ShapeObject*> shapes;
};

class Map
{
	vector<Row*> allTiles;
	Borders* borders;

public:
	vector<ShapeObject*> GetAllDrawables() const
	{
		vector<ShapeObject*> _drawables;

		for (Row* _row : allTiles)
		{
			for (Tile* _tile : _row->tiles)
			{
				_drawables.push_back(_tile->visualTile);

				if (_tile->actorOnTile)
				{
					_drawables.push_back(_tile->actorOnTile);
				}
			}
		}

		return _drawables;
	}

public:
	Map();
	~Map();

public:
	virtual void Init();
	virtual void Load();

	bool PutInMap(InteractableActor* _actor, const Vector2f& _mousePosition);
};