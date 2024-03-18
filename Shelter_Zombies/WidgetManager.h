#pragma once
#include <iostream>
#include "Singleton.h"
#include "IManager.h"
#include "Widget.h"

class WidgetManager : public Singleton<WidgetManager> , public IManager<string,Widget>
{

};

