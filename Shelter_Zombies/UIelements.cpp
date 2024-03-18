#include "UIelements.h"

UIelements::UIelements()
{
	shape = nullptr;
}

UIelements::~UIelements()
{
	delete shape;
}

