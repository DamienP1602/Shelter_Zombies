#pragma once
#include "Menu.h"
#include "MusicData.h"

/// <summary>
/// The start menu of the game
/// </summary>
class MainMenu : public Menu
{
	MusicData* music;

public:
	MainMenu();

private:
	void OpenTitleMenu();

public:
	virtual void Init() override;
};