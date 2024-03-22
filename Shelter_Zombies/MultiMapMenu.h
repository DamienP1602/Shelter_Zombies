#pragma once
#include "Menu.h"
#include "Button.h"
#include <vector>

class MultiMapMenu : public Menu
{
	vector<ShapeWidget*> buttons;
public:
	MultiMapMenu();

public:
	void Init();

	bool CheckMapLevel(const int _level);
};

