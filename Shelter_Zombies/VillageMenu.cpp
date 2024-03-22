#include "VillageMenu.h"
#include "ProgressBar.h"
#include "inventoryPlayer.h"
#include "MenuManager.h"
#include "AllyEntityManager.h"
#include "MultiMapMenu.h"


VillageMenu::VillageMenu() : Menu("PlayerVillageMenu", MenuManager::GetInstance().GetCurrent())
{
	texts = vector<TextWidget*>();
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

	InitTexts();

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

	const function<void()>& _mapCallback = [&]()
		{
			if (MenuManager::GetInstance().Get("MultiMapMenu"))
			{
				MenuManager::GetInstance().SetCurrent("MultiMapMenu");
				MenuManager::GetInstance().DisableNotCurrent();
			}
			else
			{
				new MultiMapMenu();
			}
		};

	const Vector2f& _mapButtonPosition = Vector2f(windowX * 0.95f, windowY * 0.7f);
	ShapeWidget* _mapButton = new Button(ShapeData(_mapButtonPosition, Vector2f(150.0f, 150.0f), "blue.png"), ButtonData(NULL, NULL, _mapCallback, NULL, NULL));
	canvas->AddWidget(_mapButton);

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

void VillageMenu::InitTexts()
{
	for (TextWidget* _widget : texts)
	{
		canvas->RemoveUIWidget(_widget);
	}

	const string& _textForLife = "PV " + to_string(Game::GetPlayer()->GetData()->GetActualHealth()) + " / " + to_string(Game::GetPlayer()->GetData()->GetMaximumHealth());
	TextWidget* _lifeText = new Label(TextData(_textForLife, Vector2f(windowX * 0.12f, windowY * 0.05f), "Font.ttf", 25));
	_lifeText->GetDrawable()->setOrigin(_lifeText->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	texts.push_back(_lifeText);
	canvas->AddWidget(_lifeText);

	const string& _textForTroops = to_string(AllyEntityManager::GetInstance().GetEntitiesCount()) + " / " + to_string(AllyEntityManager::GetInstance().GetMaxEntities());
	TextWidget* _troopsText = new Label(TextData(_textForTroops, Vector2f(windowX * 0.88f, windowY * 0.05f), "Font.ttf", 25));
	_troopsText->GetDrawable()->setOrigin(_troopsText->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	texts.push_back(_troopsText);
	canvas->AddWidget(_troopsText);

	const string& _textForGold = to_string(Game::GetPlayer()->GetGold());
	TextWidget* _goldText = new Label(TextData(_textForGold, Vector2f(windowX * 0.88f, windowY * 0.15f), "Font.ttf", 25));
	_goldText->GetDrawable()->setOrigin(_goldText->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	texts.push_back(_goldText);
	canvas->AddWidget(_goldText);
}

VillageMenu::~VillageMenu()
{
	delete panel;
}
