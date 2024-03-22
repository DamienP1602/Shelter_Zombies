#include "Item.h"
#include "Macro.h"
#include "Player.h"

Item::Item(const int _upgradeCost, const float _bonusValue, const int _level, const float _value,ItemWidget* _widget, const string& _fontPath, const ItemType& _type) : IManagable(GetUniqueID())
{
	value = _value;
	bonusValue = _bonusValue;
	widget = _widget;
	type = _type;
	upgradeCost = _upgradeCost;
	level = _level;
}

bool Item::TryToUpgrade(Player* _player)
{
	const int _cost = upgradeCost * level;
	if ((_player->GetGold() - _cost) < 0) return false;
	if (level == 5) return false;
	
	_player->RemoveGold(_cost);
	level++;
	value += bonusValue;
	return true;
}

string Item::GetNewPaths()
{
	if (type == IT_HELMET) return "Items/Helmet" + to_string(level) + ".png";
	if (type == IT_CHESTPLATE) return "Items/Chest" + to_string(level) + ".png";
	if (type == IT_BOOTS) return "Items/Boots" + to_string(level) + ".png";
	if (type == IT_WEAPON) return "Items/Weapon" + to_string(level) + ".png";

	return string();
}
