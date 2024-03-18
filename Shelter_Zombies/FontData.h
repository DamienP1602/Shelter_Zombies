#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "IManagable.h"

using namespace std;
using namespace sf;

class FontData : public IManagable<string>, public Font
{
public:
	FontData(const string& _path);

	virtual void Register() override;
};

