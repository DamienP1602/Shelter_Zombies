#pragma once
#include "IManagable.h"
#include "ItemWidget.h"
#include "Button.h"
#include "Label.h"

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
	int value;
	ItemWidget* widget;
	ItemType type;

public:
	int GetValue() const
	{
		return value;
	}
	string GetPath() const
	{
		return widget->GetID();
	}

public:
	Item(const int _value,ItemWidget* _widget, const string& _fontPath,const ItemType& _type);
};

