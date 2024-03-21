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
		Player* _player = Game::GetPlayer();
		allTexts.push_back("+" + to_string(_player->GetData()->equipments[0]->GetValue()) +  " dégâts.");
		allTexts.push_back("+" + to_string(_player->GetData()->equipments[1]->GetValue()) +  " dégâts.");
		allTexts.push_back("+" + to_string(_player->GetData()->equipments[2]->GetValue()) +  " vie.");
		allTexts.push_back("+" + to_string(_player->GetData()->equipments[3]->GetValue()) +  " vitesse.");

		allTexts.push_back("Soigne 25% de vie.");
		allTexts.push_back("+ 10% de soin.");
		allTexts.push_back("Boule de feu.");
		allTexts.push_back("Boule de glace.");
		allTexts.push_back("+ de portée.");
		allTexts.push_back("+ dégât contre bâtiment.");
		allTexts.push_back("Brûle les adversaires.");
		allTexts.push_back("Fragilise les adversaires.");
	}

	string GetText(const int _index)
	{
		return allTexts[_index];
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
		text = new Label(TextData("", background->GetShapePosition(), FONT,20));
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

public:
	InventoryPlayer();
	~InventoryPlayer();

public:
	void Init();
	void InitTalentTree();
};

