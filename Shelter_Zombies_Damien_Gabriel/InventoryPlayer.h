#pragma once
#include "Menu.h"
#include "ShapeWidget.h"
#include "Game.h"

struct TalentTree
{
	ShapeWidget* background;

	TalentTree()
	{
		background = nullptr;
	}
};

struct InfoText
{
	vector<string> allTexts;

	InfoText()
	{
		allTexts = vector<string>();

		Init();
	}

	string GetText(const int _index)
	{
		return allTexts[_index];
	}
	
	void Init()
	{
		allTexts.clear();

		Player* _player = Game::GetPlayer();
		allTexts.push_back("+" + to_string(int(_player->GetData()->equipments[0]->GetValue())) + " damage." + (IsLevelMax(0) ? "\nUpgrade for " + to_string(_player->GetData()->equipments[0]->GetUpgradeCost()) + " gold." : ""));
		allTexts.push_back("+" + to_string(int(_player->GetData()->equipments[1]->GetValue())) + " damage." + (IsLevelMax(1) ? "\nUpgrade for " + to_string(_player->GetData()->equipments[1]->GetUpgradeCost()) + " gold." : ""));
		allTexts.push_back("+" + to_string(int(_player->GetData()->equipments[2]->GetValue())) + " health." + (IsLevelMax(2) ? "\nUpgrade for " + to_string(_player->GetData()->equipments[2]->GetUpgradeCost()) + " gold." : ""));
		allTexts.push_back("+" + to_string(double(_player->GetData()->equipments[3]->GetValue())) + " speed." + (IsLevelMax(3) ? + "\nUpgrade for " + to_string(_player->GetData()->equipments[3]->GetUpgradeCost()) + " gold." : ""));

		allTexts.push_back("Soigne 25% de vie.");
		allTexts.push_back("+ 10% de soin.");
		allTexts.push_back("Boule de feu.");
		allTexts.push_back("Boule de glace.");
		allTexts.push_back("+ de portée.");
		allTexts.push_back("+ dégât contre bâtiment.");
		allTexts.push_back("Brûle les adversaires.");
		allTexts.push_back("Fragilise les adversaires.");
	}

	bool IsLevelMax(const int _index)
	{
		Player* _player = Game::GetPlayer();
		if (_player->GetData()->equipments[_index]->GetLevel() == 5) return false;
		return true;
	}
};

struct InformationPanel
{
	ShapeWidget* background;
	Label* text;
	InfoText data;

	InformationPanel(const Vector2f& _windowSize)
	{
		background = new ShapeWidget(ShapeData(Vector2f(_windowSize.x * 0.5f, _windowSize.y * 0.93f),Vector2f(300.0f,75.0f),"red.png"));
		text = new Label(TextData("", background->GetShapePosition() - Vector2f(0.0f,15.0f), FONT, 20));
		data = InfoText();
	}

	void SetPanel(const int _index)
	{
		text->SetString(data.GetText(_index));
	}
};

class InventoryPlayer : public Menu
{
	TalentTree* talents;
	InformationPanel* info;
	vector<ShapeWidget*> buttonsInventory;
	vector<string> statsText;
	vector<TextWidget*> stats;

public:
	InventoryPlayer();
	~InventoryPlayer();

public:
	void Init();
	void InitTalentTree();
	void InitStats();

	void Update(const int _index);
};

