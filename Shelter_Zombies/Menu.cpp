#include "Menu.h"
#include "MenuManager.h"
#include "Game.h"

#define SOUND_SELECT "Ui/ui_change_selection"

Menu::Menu(const string& _name, Menu* _owner) : IManagable(_name)
{
	Register();

	windowX = Game::GetWindowSize().x;
	windowY = Game::GetWindowSize().y;

	isInit = false;
	canvas = new Canvas(_name);
	backButton = nullptr;
	owner = _owner;
	sound = new SoundData(SOUND_SELECT, 100, false);
}

void Menu::Register()
{
	MenuManager::GetInstance().Add(id, this);
	MenuManager::GetInstance().DisableNotCurrent();
}

void Menu::Init()
{
	isInit = true;
}

void Menu::BackButton()
{
	MenuManager::GetInstance().SetCurrent(owner);
	MenuManager::GetInstance().DisableNotCurrent();
}
