#include "MenuManager.h"

void MenuManager::DisableNotCurrent()
{
	for (Menu* _menu : GetAllValues())
	{
		if (_menu != GetCurrent()) _menu->SetStatus(false);
	}
}
