#include "VillageMenu.h"
#include "ProgressBar.h"
#include "inventoryPlayer.h"
#include "MenuManager.h"


VillageMenu::VillageMenu() : Menu("PlayerVillageMenu", MenuManager::GetInstance().GetCurrent())
{
	panel = new ConstructPanel();

	Init();
}

void VillageMenu::Init()
{
	Menu::Init();
#pragma region DefaultShape

	const Vector2f& _lifePositon = Vector2f(windowX * 0.12f, windowY * 0.05f);
	ShapeWidget* _life = new ProgressBar(ShapeData(_lifePositon, Vector2f(200.0f, 50.0f), "red.png"), "red.png", PT_LEFT);
	canvas->AddWidget(_life);

	const Vector2f& _iconPosition = Vector2f(windowX * 0.05f, windowY * 0.05f);
	ShapeWidget* _icon = new ShapeWidget(ShapeData(_iconPosition, Vector2f(75.0f, 75.0f), "green.png"), WT_UI);
	canvas->AddWidget(_icon);

	const Vector2f& _troopsBarPosition = Vector2f(windowX * 0.88f, windowY * 0.05f);
	ShapeWidget* _troopsBar = new ShapeWidget(ShapeData(_troopsBarPosition, Vector2f(200.0f, 50.0f), "red.png"), WT_UI);
	canvas->AddWidget(_troopsBar);

	const Vector2f& _troopsIconPosition = Vector2f(windowX * 0.95f, windowY * 0.05f);
	ShapeWidget* _troopsIcon = new ShapeWidget(ShapeData(_troopsIconPosition, Vector2f(75.0f, 75.0f), "green.png"), WT_UI);
	canvas->AddWidget(_troopsIcon);

	const Vector2f& _goldBarPosition = Vector2f(windowX * 0.88f, windowY * 0.15f);
	ShapeWidget* _goldBar = new ShapeWidget(ShapeData(_goldBarPosition, Vector2f(200.0f, 50.0f), "red.png"), WT_UI);
	canvas->AddWidget(_goldBar);

	const Vector2f& _goldIconPosition = Vector2f(windowX * 0.95f, windowY * 0.15f);
	ShapeWidget* _goldIcon = new ShapeWidget(ShapeData(_goldIconPosition, Vector2f(75.0f, 75.0f), "green.png"), WT_UI);
	canvas->AddWidget(_goldIcon);

#pragma endregion

#pragma region Texts

	TextWidget* _lifeText = new Label(TextData("0/20 life", _lifePositon, "Font.ttf", 25));
	_lifeText->GetDrawable()->setOrigin(_lifeText->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	canvas->AddWidget(_lifeText);

	TextWidget* _troopsText = new Label(TextData("0/20 troops", _troopsBarPosition, "Font.ttf", 25));
	_troopsText->GetDrawable()->setOrigin(_troopsText->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	canvas->AddWidget(_troopsText);

	TextWidget* _goldText = new Label(TextData("0/20 gold", _goldBarPosition, "Font.ttf", 25));
	_goldText->GetDrawable()->setOrigin(_goldText->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	canvas->AddWidget(_goldText);

#pragma endregion

#pragma region Buttons

	const function<void()>& _callback = [&]()
		{
			if (MenuManager::GetInstance().Get("InventoryPlayerMenu"))
			{
				MenuManager::GetInstance().SetCurrent("InventoryPlayerMenu");
				MenuManager::GetInstance().DisableNotCurrent();
			}
			else
			{
				new InventoryPlayer();
			}
		};
	const Vector2f& _characterButtonPosition = Vector2f(windowX * 0.95f, windowY * 0.9f);
	ShapeWidget* _characterButton = new Button(ShapeData(_characterButtonPosition,Vector2f(150.0f,150.0f),"red.png"), ButtonData(NULL, NULL, _callback, NULL, NULL));
	canvas->AddWidget(_characterButton);

	const Vector2f& _contructButtonPosition = Vector2f(windowX * 0.05f, windowY * 0.95f);
	
	function<void()> _callbacks[] = {
		[&]() {RemoveFromCanva(); panel->InitWalls(); AddToCanva(); },
		[&]() {RemoveFromCanva(); panel->InitDefenses(); AddToCanva(); },
		[&]() {RemoveFromCanva(); panel->InitTraps(); AddToCanva(); },
		[&]() {RemoveFromCanva(); panel->InitCasern(); AddToCanva(); }
	};

	for (int _i = 0; _i < 4; _i++)
	{
		const Vector2f& _gap = Vector2f((100.f * _i), 0.0f);
		ShapeWidget* _constructButton1 = new Button(ShapeData(_contructButtonPosition + _gap, Vector2f(75.0f, 75.0f), "green.png"),ButtonData(NULL,NULL, _callbacks[_i], NULL, NULL));
		canvas->AddWidget(_constructButton1);
	}

#pragma endregion

#pragma region ConstructPanel

	const Vector2f& _backgroundBuildingsPosition = Vector2f(windowX * 0.13f, windowY * 0.85f);
	panel->SetBackground(new ShapeWidget(ShapeData(_backgroundBuildingsPosition,Vector2f(450.0f,100.f),"white.png")));

	canvas->AddWidget(panel->GetBackground());

#pragma endregion

}

void VillageMenu::RemoveFromCanva()
{
	for (ConstructElements* _element : panel->GetAllWidget())
	{
		if (_element->isInCanva)
		{
			for (ShapeWidget* _widget : _element->allBuildings)
			{
				canvas->RemoveUIWidget(_widget);
			}
			_element->isInCanva = false;
			return;
		}
	}
}

void VillageMenu::AddToCanva()
{
	for (ConstructElements* _element : panel->GetAllWidget())
	{
		if (_element->isInCanva)
		{
			for (ShapeWidget* _widget : _element->allBuildings)
			{
				canvas->AddWidget(_widget);
			}
			return;
		}
	}
}

VillageMenu::~VillageMenu()
{
	delete panel;
}
