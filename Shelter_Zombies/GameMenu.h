#pragma once
#include "Menu.h"
#include <vector>

class GameMenu : public Menu
{
	ShapeWidget* index;
	vector<ShapeWidget*> buttons;
public:
	GameMenu();

public:
	void Init();
	void ChangeIndexPosition(const int _index);
};

