#pragma once
#include "Canvas.h"
#include "ShapeWidget.h"

struct TalentTree
{
	ShapeWidget* background;

	TalentTree()
	{
		background = nullptr;
	}
};

class InventoryPlayer : public Canvas
{
	TalentTree* talents;

public:
	InventoryPlayer();
	~InventoryPlayer();

public:
	void Init();
	void InitTalentTree();
};

