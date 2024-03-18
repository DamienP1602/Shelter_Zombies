#pragma once
#include "Menu.h"
#include "AudioMenu.h"
#include "ControllerMenu.h"
#include "KeyboardMenu.h"


class OptionsMenu : public Menu
{
	vector<Button*> buttons;
	AudioMenu* audio;
	ControllerMenu* controller;
	KeyboardMenu* keyboard;
	ShapeWidget* pointer;

public:
	OptionsMenu(Menu* _owner);

public:
	virtual void Init() override;
};