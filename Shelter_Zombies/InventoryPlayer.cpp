#include "InventoryPlayer.h"
#include "TextWidget.h"
#include "MenuManager.h"

InventoryPlayer::InventoryPlayer() : Menu("InventoryPlayerMenu",MenuManager::GetInstance().GetCurrent())
{
	talents = new TalentTree();

	Init();
}

InventoryPlayer::~InventoryPlayer()
{
	delete talents;
}

void InventoryPlayer::Init()
{
	Menu::Init();

	const Vector2f& _backgroundPosition = Vector2f(windowX * 0.5f, windowY * 0.5f);
	ShapeWidget* _background = new ShapeWidget(ShapeData(_backgroundPosition, Vector2f(1000.0f, 800.0f), "white.png"));
	canvas->AddWidget(_background);

	const Vector2f& _itemsBackgroundPosition = Vector2f(windowX * 0.22f, windowY * 0.5f);
	ShapeWidget* _itemsBackground = new ShapeWidget(ShapeData(_itemsBackgroundPosition, Vector2f(150.0f, 600.0f), "blue.png"));
	canvas->AddWidget(_itemsBackground);

	const Vector2f& _leftBackgroundPosition = Vector2f(windowX * 0.3625f,windowY * 0.5f);
	ShapeWidget* _leftBackground = new ShapeWidget(ShapeData(_leftBackgroundPosition, Vector2f(400.0f, 750.0f), "red.png"));
	canvas->AddWidget(_leftBackground);

	const Vector2f& _rightBackgroundPosition = Vector2f(windowX * 0.6125f, windowY * 0.5f);
	ShapeWidget* _rightBackground = new ShapeWidget(ShapeData(_rightBackgroundPosition, Vector2f(500.0f, 750.0f), "blue.png"));
	canvas->AddWidget(_rightBackground);

	const Vector2f& _playerBackgroundPosition = Vector2f(_leftBackgroundPosition.x, windowY * 0.35f);
	ShapeWidget* _playerBackground = new ShapeWidget(ShapeData(_playerBackgroundPosition, Vector2f(275.0f, 250.0f), "green.png"));
	canvas->AddWidget(_playerBackground);

	const Vector2f& _playerNamePosition = Vector2f(_playerBackgroundPosition.x, windowY * 0.2f);
	TextWidget* _playerName = new TextWidget(TextData("player name", _playerNamePosition, "Font.ttf",25));
	_playerName->GetDrawable()->setOrigin(_playerName->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	canvas->AddWidget(_playerName);

	const Vector2f& _playerLevelPosition = Vector2f(_playerBackgroundPosition.x, windowY * 0.48f);
	TextWidget* _playerLevel = new TextWidget(TextData("player level", _playerLevelPosition, "Font.ttf", 25));
	_playerLevel->GetDrawable()->setOrigin(_playerLevel->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	canvas->AddWidget(_playerLevel);

	const Vector2f& _statsBackgroundPosition = Vector2f(_playerBackgroundPosition.x, windowY * 0.6f);
	ShapeWidget* _statsBackground = new ShapeWidget(ShapeData(_statsBackgroundPosition, Vector2f(300.0f, 150.0f), "green.png"));
	canvas->AddWidget(_statsBackground);

	const Vector2f& _weaponBackgroundPosition = Vector2f(_playerBackgroundPosition.x, windowY * 0.75f);
	ShapeWidget* _weaponBackground = new ShapeWidget(ShapeData(_weaponBackgroundPosition, Vector2f(125.0f, 125.0f), "green.png"));
	canvas->AddWidget(_weaponBackground);

	const Vector2f& _spellsBackgroundPosition = Vector2f(windowX * 0.575f, windowY * 0.25f);
	ShapeWidget* _spellsBackground = new ShapeWidget(ShapeData(_spellsBackgroundPosition, Vector2f(275.0f, 100.0f), "green.png"));
	canvas->AddWidget(_spellsBackground);

	const Vector2f& _pointsBackgroundPosition = Vector2f(windowX * 0.7f, windowY * 0.25f);
	ShapeWidget* _pointsBackground = new ShapeWidget(ShapeData(_pointsBackgroundPosition, Vector2f(100.0f, 100.0f), "green.png"));
	canvas->AddWidget(_pointsBackground);

	const Vector2f& _spellPosition = Vector2f(_spellsBackgroundPosition.x, windowY * 0.25f);
	for (int _i = 0; _i < 3; _i++)
	{
		const Vector2f& _gap = Vector2f((-90.0f + (90.0f * _i)),0.0f);
		canvas->AddWidget(new ShapeWidget(ShapeData(_spellPosition + _gap, Vector2f(75.0f, 75.0f), "yellow.png")));
	}

	const Vector2f& _talentTreePosition = Vector2f(_rightBackgroundPosition.x ,windowY * 0.575f);
	talents->background = new ShapeWidget(ShapeData(_talentTreePosition,Vector2f(450.0f,500.0f),"green.png"));
	canvas->AddWidget(talents->background);

	const Vector2f& _backButtonPosition = Vector2f((_backgroundPosition.x + _background->GetShapeSize().x / 2.0f) - 25.0f, (_backgroundPosition.y - _background->GetShapeSize().y / 2.0f) + 25.0f);
	backButton = new Button(ShapeData(_backButtonPosition, Vector2f(50.0f, 50.0f), "red.png"), ButtonData(NULL, NULL, [&]() {BackButton(); }, NULL, NULL));
	canvas->AddWidget(backButton);

	string _names[] = {
		"Weapon",
		"Head",
		"Chest",
		"Boots"
	};

	function<void()> _callbacks[] = {
		[&]() {cout << "Weapon" << endl; },
		[&]() {cout << "Head" << endl; },
		[&]() {cout << "Chest" << endl; },
		[&]() {cout << "Boots" << endl; }
	};

	for (int _i = 0; _i < 4; _i++)
	{
		const Vector2f& _gap = Vector2f(0.0f,-225 + (150.0f * _i));
		ShapeWidget* _button = new Button(ShapeData(_itemsBackgroundPosition + _gap,Vector2f(100.0f,100.0f),"red.png"),ButtonData(NULL,NULL,_callbacks[_i],NULL,NULL));
		TextWidget* _name = new Label(TextData(_names[_i], _button->GetShapePosition(),FONT));
		_name->GetDrawable()->setPosition(_button->GetShapePosition().x, _button->GetShapePosition().y + 30.0f);
		canvas->AddWidget(_button);
		canvas->AddWidget(_name);

	}

	InitTalentTree();

}

void InventoryPlayer::InitTalentTree()
{
	const Vector2f& _backgroundPosition = talents->background->GetShapePosition();
	const Vector2f& _talentSize = Vector2f(75.0f, 75.0f);

	const Vector2f& _firstTalentPosition = Vector2f(_backgroundPosition.x, _backgroundPosition.y * 1.3f);
	ShapeWidget* _firstTalent = new ShapeWidget(ShapeData(_firstTalentPosition, _talentSize, "yellow.png"));
	canvas->AddWidget(_firstTalent);

	const Vector2f& _secondTalentPosition = Vector2f(_backgroundPosition.x, _backgroundPosition.y * 1.15f);
	ShapeWidget* _secondTalent = new ShapeWidget(ShapeData(_secondTalentPosition, _talentSize, "yellow.png"));
	canvas->AddWidget(_secondTalent);

	const Vector2f& _thirdTalentPosition = Vector2f(_backgroundPosition.x * 0.95f, _backgroundPosition.y * 0.95f);
	ShapeWidget* _thirdTalent = new ShapeWidget(ShapeData(_thirdTalentPosition, _talentSize, "yellow.png"));
	canvas->AddWidget(_thirdTalent);

	const Vector2f& _fourthTalentPosition = Vector2f(_backgroundPosition.x * 1.05f, _backgroundPosition.y * 0.95f);
	ShapeWidget* _fourthTalent = new ShapeWidget(ShapeData(_fourthTalentPosition, _talentSize, "yellow.png"));
	canvas->AddWidget(_fourthTalent);

	const Vector2f& _fifthTalentPosition = Vector2f(_backgroundPosition.x * 0.85f, _backgroundPosition.y * 0.85f);
	ShapeWidget* _fifthTalent = new ShapeWidget(ShapeData(_fifthTalentPosition, _talentSize, "yellow.png"));
	canvas->AddWidget(_fifthTalent);

	const Vector2f& _sixthTalentPosition = Vector2f(_backgroundPosition.x * 1.15f, _backgroundPosition.y * 0.85f);
	ShapeWidget* _sixthTalent = new ShapeWidget(ShapeData(_sixthTalentPosition, _talentSize, "yellow.png"));
	canvas->AddWidget(_sixthTalent);

	const Vector2f& _seventhTalentPosition = Vector2f(_backgroundPosition.x * 0.925f, _backgroundPosition.y * 0.7f);
	ShapeWidget* _seventhTalent = new ShapeWidget(ShapeData(_seventhTalentPosition, _talentSize, "yellow.png"));
	canvas->AddWidget(_seventhTalent);

	const Vector2f& _eithTalentPosition = Vector2f(_backgroundPosition.x * 1.075f, _backgroundPosition.y * 0.7f);
	ShapeWidget* _eithTalent = new ShapeWidget(ShapeData(_eithTalentPosition, _talentSize, "yellow.png"));
	canvas->AddWidget(_eithTalent);
}
