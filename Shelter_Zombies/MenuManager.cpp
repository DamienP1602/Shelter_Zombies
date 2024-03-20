#include "MenuManager.h"

void MenuManager::DisableNotCurrent()
{
	for (Menu* _menu : GetAllValues())
	{
		if (_menu != GetCurrent()) _menu->SetStatus(false);
		else if (_menu->GetCanvas()) _menu->SetStatus(true);
	}
}
