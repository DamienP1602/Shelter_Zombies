#include "Item.h"
#include "Macro.h"

Item::Item(const int _value,ItemWidget* _widget, const string& _fontPath, const ItemType& _type) : IManagable(GetUniqueID())
{
	value = _value;
	widget = _widget;
	type = _type;
}