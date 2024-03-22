#pragma once
#include "IManagable.h"
#include "ItemWidget.h"
#include "Button.h"
#include "Label.h"

class Player;

enum ItemType
{
	IT_NONE,
	IT_HELMET,
	IT_CHESTPLATE,
	IT_BOOTS,
	IT_WEAPON
};

struct ItemData
{
	string path;
	string title;
	string text;
	ItemType type;
};

class Item : public IManagable<int>
{
	float value;
	float bonusValue;
	int upgradeCost;
	int level;
	ItemWidget* widget;
	ItemType type;

public:
	int GetUpgradeCost() const
	{
		return int(upgradeCost * level);
	}
	float GetValue() const
	{
		return value;
	}
	string GetPath() const
	{
		return widget->GetID();
	}
	int GetLevel() const
	{
		return level;
	}

public:
	Item(const int _upgradeCost,const float _bonusValue,const int _level,const float _value,ItemWidget* _widget, const string& _fontPath,const ItemType& _type);

public:
	void TryToUpgrade(Player* _player);

	string GetNewPaths();
};

