#pragma once
#include "Menu.h"
#include "ShapeWidget.h"
#include "Label.h"
#include <vector>

class BarrackMenu : public Menu
{
	//Barack
public:
	BarrackMenu();

public:
	void Init();
	void InitTroop(const Vector2f& _positionGap);
};

