#include "GameMenu.h"
#include "MenuManager.h"
#include "ShapeWidget.h"
#include "TextWidget.h"
#include "Game.h"

GameMenu::GameMenu() : Menu("GameMenu",MenuManager::GetInstance().GetCurrent())
{
	Init();
}

void GameMenu::Init()
{
	Menu::Init();

	const Vector2f& _blackShapePosition = Vector2f(windowX * 0.5f,windowY * 0.5f);
	ShapeWidget* _blackShape = new ShapeWidget(ShapeData(_blackShapePosition,Vector2f(windowX,windowY)));
	_blackShape->GetDrawable()->setFillColor(Color(0, 0, 0, 125));
	canvas->AddWidget(_blackShape);

	string _names[] = {
		"Continuer",
		"Option",
		"Credit",
		"Quitter"
	};

	function<void()> _callbacks[] = {
		[&]() {cout << "Continuer" << endl; MenuManager::GetInstance().SetCurrent(owner); MenuManager::GetInstance().DisableNotCurrent(); },
		[&]() {cout << "Option" << endl; },
		[&]() {cout << "Credit" << endl; },
		[&]() {cout << "Quitter" << endl; Game::GetWindow().close(); }
	};

	function<void()> _grapghicCallbacks[] = {
	[&]() {ChangeIndexPosition(0); },
	[&]() {ChangeIndexPosition(1); },
	[&]() {ChangeIndexPosition(2); },
	[&]() {ChangeIndexPosition(3); }
	};
	
	for (int _i = 0; _i < 4; _i++)
	{
		const Vector2f& _gap = Vector2f(0.0f, -200.0f + (100.0f * _i));
		TextWidget* _text = new Label(TextData(_names[_i], _blackShapePosition + _gap,FONT,40));
		ShapeWidget* _button = new Button(ShapeData(_text->GetDrawable()->getPosition(), _text->GetDrawable()->getGlobalBounds().getSize(), "red.png"), ButtonData(_grapghicCallbacks[_i], NULL, _callbacks[_i], NULL, NULL));
		_text->GetDrawable()->setPosition(_text->GetDrawable()->getPosition() + Vector2f(0.0f,-15.0f));
		_button->GetDrawable()->setFillColor(Color(0, 0, 0, 0));
		canvas->AddWidget(_button);
		canvas->AddWidget(_text);

		buttons.push_back(_button);
	}

	const Vector2f& _baseIndexPosition = Vector2f((buttons[0]->GetShapePosition().x - (buttons[0]->GetDrawable()->getGlobalBounds().getSize().x / 1.4f)), buttons[0]->GetShapePosition().y);
	index = new ShapeWidget(ShapeData(_baseIndexPosition, Vector2f(50.0f, 20.0f), "blue.png"));
	canvas->AddWidget(index);

}

void GameMenu::ChangeIndexPosition(const int _index)
{
	index->GetDrawable()->setPosition(Vector2f((buttons[_index]->GetShapePosition().x - (buttons[_index]->GetDrawable()->getGlobalBounds().getSize().x / 1.4f)), buttons[_index]->GetShapePosition().y));
}
