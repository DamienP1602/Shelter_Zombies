#pragma once
#include <iostream>
#include "FontData.h"
#include "Singleton.h"
#include "IManager.h"
#include "IManagable.h"

using namespace std;

class FontManager : public Singleton<FontManager>, public IManager<string,FontData>
{
public:
	void Load(Text* _text, const string& _path,const bool _isSmooth = true);
};

