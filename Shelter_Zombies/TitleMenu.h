#pragma once
#include "Menu.h"
#include "OptionsMenu.h"
#include "QuitGameMenu.h"

class TitleMenu : public Menu
{
	vector<Button*> buttons;
	OptionsMenu* options;
	QuitGameMenu* quitGame;

public:
	virtual void SetStatus(const bool _status)
	{
		options->SetOwner(this);
		Menu::SetStatus(_status);
	}

public:
	TitleMenu(Menu* _owner);

public:
	virtual void Init() override;
};