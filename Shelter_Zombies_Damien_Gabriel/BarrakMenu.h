#pragma once
#include "Menu.h"
#include "ShapeWidget.h"
#include "Label.h"
#include <vector>
#include "Barrack.h"

struct TroopsInformations
{
	string name;
	int cost;
	int damage;
	int life;

	TroopsInformations(const string& _name, const int _cost, const int _damage, const int _life)
	{
		name = _name;
		cost = _cost;
		damage = _damage;
		life = _life;
	}
};

struct AllTroops
{
	vector<TroopsInformations> troops;

	AllTroops()
	{
		troops.push_back(TroopsInformations("Fighter", 20, 3, 6));
		troops.push_back(TroopsInformations("Shooter", 15, 6, 3));
		troops.push_back(TroopsInformations("Support", 30, 1, 7));
		troops.push_back(TroopsInformations("Artillery", 50, 8, 2));
	}
};

class BarrackMenu : public Menu
{
	Canvas* buildingCanvas;

	AllTroops data;

public:

public:
	BarrackMenu();

public:
	void Init();
	void InitTroop(const Vector2f& _positionGap,const int _index);
};

