#pragma once
#include "Menu.h"
#include "Timer.h"

class Merchand;

class ShopMenu : public Menu
{
	float timeBeforeOpenShop;
	vector<Button*> buttons;
	Label* descriptionTitle;
	Label* descriptionText;
	Timer* timer;

	Merchand* merchand;

public:
	ShopMenu(Menu* _owner, Merchand* _merchand);

public:
	virtual void Init() override;
	virtual void SetStatus(const bool _status, const bool _applyToWidgets = true) override;
	void Open();
};