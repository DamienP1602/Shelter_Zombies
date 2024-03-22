#include "MultiMapMenu.h"
#include "MenuManager.h"
#include "Label.h"

#define MAP_PATH "WorldMap.png"

MultiMapMenu::MultiMapMenu() : Menu("MultiMapMenu",MenuManager::GetInstance().GetCurrent())
{
	Init();
}

void MultiMapMenu::Init()
{
	Vector2f _positions[] = {
		Vector2f(windowX * 0.32f, windowY * 0.3f),
		Vector2f(windowX * 0.34f, windowY * 0.45f),
		Vector2f(windowX * 0.41f, windowY * 0.55f),
		Vector2f(windowX * 0.51f, windowY * 0.56f),
		Vector2f(windowX * 0.43f, windowY * 0.35f),
		Vector2f(windowX * 0.52f, windowY * 0.29f),
		Vector2f(windowX * 0.64f, windowY * 0.29f),
		Vector2f(windowX * 0.61f, windowY * 0.41f),
		Vector2f(windowX * 0.64f, windowY * 0.55f)
	};

	string _names[] = {
		"Votre Base",
		"Avant Post 1",
		"Avant Post 2",
		"Avant Post 3",
		"Avant Post 4",
		"Avant Post 5",
		"Avant Post 6",
		"Avant Post 7",
		"Base Adverse",

	};

	ShapeWidget* _background = new ShapeWidget(ShapeData(Vector2f(windowX * 0.5f,windowY * 0.5f), Vector2f(1200.0f, 700.0f), MAP_PATH));
	canvas->AddWidget(_background);

	for (int _i = 0; _i < 9; _i++)
	{
		TextWidget* _text1 = new Label(TextData(_names[_i], _positions[_i], FONT, 20));
		canvas->AddWidget(_text1);
	}

	const Vector2f& _gap = Vector2f(0.0f, 50.0f);
	const Vector2f& _size = Vector2f(75.0f, 50.0f);
	for (int _i = 0; _i < 8; _i++)
	{
		ShapeWidget* _buttonBase = new Button(ShapeData(_positions[_i] + _gap, _size));
		_buttonBase->GetDrawable()->setFillColor(Color::Transparent);
		canvas->AddWidget(_buttonBase);
	}

	
}
