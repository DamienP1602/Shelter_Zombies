#pragma once
#include "Menu.h"
#include "ShapeWidget.h"

struct TalentTree
{
	ShapeWidget* background;

	TalentTree()
	{
		background = nullptr;
	}
};

class InventoryPlayer : public Menu
{
	TalentTree* talents;

public:
	InventoryPlayer();
	~InventoryPlayer();

public:
	void Init();
	void InitTalentTree();
};

