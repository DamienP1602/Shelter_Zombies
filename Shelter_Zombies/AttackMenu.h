#pragma once
#include "Menu.h"
#include "TextWidget.h"

class AttackMenu : public Menu
{
	vector<TextWidget*> texts;
public:
	AttackMenu();

public:
	void Init();
	void InitText();
};

