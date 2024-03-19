#include "BarrakMenu.h"
#include "MenuManager.h"

BarrackMenu::BarrackMenu() : Menu("CasernMenu",MenuManager::GetInstance().GetCurrent())
{

	Init();
}

void BarrackMenu::Init()
{
	const Vector2f& _leftBackgroundPosition = Vector2f(windowX * 0.225f,windowY * 0.5f);
	ShapeWidget* _leftBackground = new ShapeWidget(ShapeData(_leftBackgroundPosition,Vector2f(300.0f,750.0f),"white.png"));
	canvas->AddWidget(_leftBackground);

	const Vector2f& _rightBackgroundPosition = Vector2f(windowX * 0.5f, windowY * 0.5f);
	ShapeWidget* _rightBackground = new ShapeWidget(ShapeData(_rightBackgroundPosition, Vector2f(650.0f, 450.0f), "blue.png"));
	canvas->AddWidget(_rightBackground);

	const Vector2f& _buildingBackgroundPosition = Vector2f(windowX * 0.4125f, windowY * 0.45f);
	ShapeWidget* _buildingBackground = new ShapeWidget(ShapeData(_buildingBackgroundPosition, Vector2f(200.0f, 150.0f), "red.png"));
	canvas->AddWidget(_buildingBackground);

	const Vector2f& _nameBackgroundPosition = Vector2f(windowX * 0.5f, windowY * 0.35f);
	ShapeWidget* _nameBackground = new ShapeWidget(ShapeData(_nameBackgroundPosition, Vector2f(400.0f, 50.0f), "red.png"));
	canvas->AddWidget(_nameBackground);

	const Vector2f& _namePosition = Vector2f(_nameBackgroundPosition.x, _nameBackgroundPosition.y - 10.0f);
	TextWidget* _name = new Label(TextData("Nom Building", _namePosition, "Font.ttf", 25));
	canvas->AddWidget(_name);

	const Vector2f& _lifeBackgroundPosition = Vector2f(windowX * 0.5625f, windowY * 0.4125f);
	ShapeWidget* _lifeBackground = new ShapeWidget(ShapeData(_lifeBackgroundPosition, Vector2f(250.0f, 50.0f), "red.png"));
	canvas->AddWidget(_lifeBackground);

	const Vector2f& _lifePosition = Vector2f(_lifeBackgroundPosition.x, _lifeBackgroundPosition.y - 10.0f);
	TextWidget* _life = new Label(TextData("Vie Building", _lifePosition, "Font.ttf", 25));
	canvas->AddWidget(_life);

	const function<void()>& _upgradeCallback = [&]() {cout << "Update" << endl; };
	const Vector2f& _upgradeButtonPosition = Vector2f(_lifeBackgroundPosition.x - 100.0f, windowY * 0.475f);
	ShapeWidget* _upgradeButton = new Button(ShapeData(_upgradeButtonPosition, Vector2f(150.0f, 50.0f), "red.png"), ButtonData(NULL, NULL, _upgradeCallback, NULL, NULL));
	canvas->AddWidget(_upgradeButton);

	const function<void()>& _destroyCallback = [&]() {cout << "Destroy" << endl; };
	const Vector2f& _destroyButtonPosition = Vector2f(_lifeBackgroundPosition.x + 100.0f, windowY * 0.475f);
	ShapeWidget* _destroyButton = new Button(ShapeData(_destroyButtonPosition, Vector2f(150.0f, 50.0f), "red.png"), ButtonData(NULL, NULL, _destroyCallback, NULL, NULL));
	canvas->AddWidget(_destroyButton);

	const Vector2f& _upgradeTextPosition = Vector2f(_upgradeButtonPosition.x, _upgradeButtonPosition.y - 10.0f);
	TextWidget* _upgrade = new Label(TextData("Upgrade", _upgradeTextPosition, "Font.ttf", 25));
	canvas->AddWidget(_upgrade);

	const Vector2f& _destroyTextPosition = Vector2f(_destroyButtonPosition.x, _destroyButtonPosition.y - 10.0f);
	TextWidget* _destroy = new Label(TextData("Destroy", _destroyTextPosition, "Font.ttf", 25));
	canvas->AddWidget(_destroy);

	const function<void()>& _createCallback = [&]() {cout << "Create" << endl; };
	const Vector2f& _createButtonPosition = Vector2f(_lifeBackgroundPosition.x, windowY * 0.5325f);
	ShapeWidget* _createButton = new Button(ShapeData(_createButtonPosition, Vector2f(200.0f, 50.0f), "red.png"), ButtonData(NULL, NULL, _createCallback, NULL, NULL));
	canvas->AddWidget(_createButton);

	const Vector2f& _createTextPosition = Vector2f(_createButtonPosition.x, _createButtonPosition.y - 10.0f);
	TextWidget* _create = new Label(TextData("Create", _createTextPosition, "Font.ttf", 25));
	canvas->AddWidget(_create);

	InitTroop(Vector2f());
}

void BarrackMenu::InitTroop(const Vector2f& _positionGap)
{
	const Vector2f& _backgroundPosition = Vector2f(windowX * 0.225f, windowY * 0.25f) + _positionGap;
	ShapeWidget* _background = new ShapeWidget(ShapeData(_backgroundPosition, Vector2f(250.0f, 150.0f), "red.png"));
	canvas->AddWidget(_background);

	const Vector2f& _troopBackgroundPosition = Vector2f(_backgroundPosition.x - 50.0f, _backgroundPosition.y) + _positionGap;
	ShapeWidget* _troopBackground = new ShapeWidget(ShapeData(_troopBackgroundPosition, Vector2f(100.0f, 100.0f), "blue.png"));
	canvas->AddWidget(_troopBackground);

}
