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
	ItemWidget* widget;
	Label* countText;

public:
	string GetPath() const
	{
		return widget->GetID();
	}
	Label* GetCountText() const
	{
		return countText;
	}

public:
	Item(ItemWidget* _widget, const string& _fontPath);
};

