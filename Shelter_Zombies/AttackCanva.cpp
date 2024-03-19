#include "AttackCanva.h"
#include "ProgressBar.h"
#include "Label.h"
#include "Button.h"

AttackCanva::AttackCanva() : Canvas("AttackCanva")
{
	Init();
}

void AttackCanva::Init()
{
	const Vector2f& _lifePositon = Vector2f(windowX * 0.12f, windowY * 0.05f);
	ShapeWidget* _life = new ProgressBar(ShapeData(_lifePositon, Vector2f(200.0f, 50.0f), "red.png"), "red.png", PT_LEFT);
	AddWidget(_life);

	const Vector2f& _iconPosition = Vector2f(windowX * 0.05f, windowY * 0.05f);
	ShapeWidget* _icon = new ShapeWidget(ShapeData(_iconPosition, Vector2f(75.0f, 75.0f), "green.png"), WT_UI);
	AddWidget(_icon);

	const Vector2f& _troopsBarPosition = Vector2f(windowX * 0.88f, windowY * 0.05f);
	ShapeWidget* _troopsBar = new ShapeWidget(ShapeData(_troopsBarPosition, Vector2f(200.0f, 50.0f), "red.png"), WT_UI);
	AddWidget(_troopsBar);

	const Vector2f& _troopsIconPosition = Vector2f(windowX * 0.95f, windowY * 0.05f);
	ShapeWidget* _troopsIcon = new ShapeWidget(ShapeData(_troopsIconPosition, Vector2f(75.0f, 75.0f), "green.png"), WT_UI);
	AddWidget(_troopsIcon);

	TextWidget* _lifeText = new Label(TextData("0/20 life", _lifePositon, "Font.ttf", 25));
	_lifeText->GetDrawable()->setOrigin(_lifeText->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	AddWidget(_lifeText);

	TextWidget* _troopsText = new Label(TextData("0/20 troops", _troopsBarPosition, "Font.ttf", 25));
	_troopsText->GetDrawable()->setOrigin(_troopsText->GetDrawable()->getGlobalBounds().getSize() / 2.0f);
	AddWidget(_troopsText);

	function<void()> _callbacks[] = {
		[&]() {cout << "Sort 1" << endl; },
		[&]() {cout << "Sort 2" << endl; },
		[&]() {cout << "Sort 3" << endl; }
	};

	const Vector2f& _spellPosition = Vector2f(windowX * 0.05f, windowY * 0.85f);
	for (int _i = 0; _i < 3; _i++)
	{
		const Vector2f& _gap = Vector2f((175.0f * _i), 0.0f);
		ShapeWidget* _button = new Button(ShapeData(_spellPosition + _gap, Vector2f(125.0f,125.0f), "green.png"),ButtonData(NULL,NULL, _callbacks[_i], NULL, NULL));
		AddWidget(_button);
	}
}
