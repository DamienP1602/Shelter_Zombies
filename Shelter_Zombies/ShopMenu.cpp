#include "ShopMenu.h"
#include "Game.h"
#include "HUD.h"

#define PATH_ITEM "UIs/Inventory/Core.png"
#define PATH_LANTERN "UIs/Inventory/Lantern.png"

#define PATH_SHOP "UIs/Shop/Shop.png"
#define PATH_GEO "UIs/Shop/Geo.png"

ShopMenu::ShopMenu(Menu* _owner, Merchand* _merchand) : Menu("Shop", _owner)
{
	timeBeforeOpenShop = 8.0f;
	buttons = vector<Button*>();
	descriptionTitle = nullptr;
	descriptionText = nullptr;
	timer = nullptr;
	merchand = _merchand;
}


void ShopMenu::Init()
{
	const Vector2f& _windowSize = Game::GetWindowSize();
	const Vector2f& _halfWindowSize = Game::GetWindowSize() / 2.0f;

	#pragma region Background

	const Vector2f& _shopSize = Vector2f(_halfWindowSize.x * 0.8f, _windowSize.y);
	const Vector2f& _shopPos = Vector2f(_halfWindowSize.x + _shopSize.x / 2.0f, _halfWindowSize.y);
	ShapeWidget* _shop = new ShapeWidget(ShapeData(_shopPos, _shopSize, PATH_SHOP));
	canvas->AddWidget(_shop);

	#pragma endregion

	#pragma region Grid
	const float _widgetPosX = _shopPos.x - _shopSize.x * 0.35f;
	const Vector2f& _widgetSize = Vector2f(60.0f, 60.0f);
	const float _geoPosX = _widgetPosX + _widgetSize.x;
	const Vector2f& _geoSize = Vector2f(30.0f, 30.0f);
	const float _geoTextPosX = _geoPosX + _geoSize.x * 0.8f;
	const float _startPosY = _shopPos.y - _shopSize.y * 0.275f;
	const float _gapY = 10.0f;
	const Vector2f& _buttonSize = Vector2f(_shopSize.x * 0.4f, _widgetSize.y + _widgetSize.y * 0.7f);
	const float _buttonPosX = _widgetPosX + _buttonSize.x * 0.2f;
	int _index = 0;
	#pragma region Pointer

	Menu::Init();

	#pragma endregion

	#pragma endregion

	#pragma region Description

	const Vector2f& _descriptionSize = Vector2f(_shopSize.x / 2.0f, _shopSize.y * 0.6f);
	const Vector2f& _descriptionPos = _shopPos + Vector2f(_descriptionSize.x * 0.3f, 0.0f);
	/*ShapeWidget* _description = new ShapeWidget(ShapeData(_descriptionPos, _descriptionSize, ""));
	canvas->AddWidget(_description);*/

	#pragma region Title

	const float _descriptionTitlePosX = _descriptionPos.x;
	const float _descriptionTitlePosY = _descriptionPos.y - _descriptionPos.y / 2.0f;
	const Vector2f& _descriptionTitlePos = Vector2f(_descriptionTitlePosX, _descriptionTitlePosY);
	descriptionTitle = new Label(TextData("", _descriptionTitlePos, FONT, 22), AT_CENTER);
	canvas->AddWidget(descriptionTitle);

	#pragma endregion

	#pragma region Text

	const float _descriptionTextPosX = _descriptionPos.x - _descriptionSize.x * 0.45f;
	const float _descriptionTextPosY = _descriptionTitlePosY + _descriptionSize.y * 0.15f;
	const Vector2f& _descriptionLabelPos = Vector2f(_descriptionTextPosX, _descriptionTextPosY);
	descriptionText = new Label(TextData("", _descriptionLabelPos, FONT, 13), AT_LEFT);
	canvas->AddWidget(descriptionText);

	#pragma endregion

	#pragma endregion
}

void ShopMenu::SetStatus(const bool _status, const bool _applyToWidgets)
{
	if (!_status)
	{
		timer = nullptr;
		Menu::SetStatus(false);
	}

	else
	{
		timer = new Timer([&]() {
			Open();
		}, seconds(timeBeforeOpenShop));
	}
}

void ShopMenu::Open()
{
	Menu::SetStatus(true);
}