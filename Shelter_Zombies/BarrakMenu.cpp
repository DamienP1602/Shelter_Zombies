#include "BarrakMenu.h"
#include "MenuManager.h"
#include "BuildingMenu.h"

BarrackMenu::BarrackMenu() : Menu("CasernMenu",MenuManager::GetInstance().GetCurrent())
{
	data = AllTroops();
	Init();
}

void BarrackMenu::Init()
{
	if (BuildingMenu* _building = dynamic_cast<BuildingMenu*>(MenuManager::GetInstance().Get("BuildingMenu")))
	{
		buildingCanvas = _building->GetCanvas();
	}

	for (Widget* _widget : buildingCanvas->GetUiWidgets())
	{
		_widget->SetVisible(true);
		canvas->AddWidget(_widget);
	}

	const Vector2f& _leftBackgroundPosition = Vector2f(windowX * 0.225f,windowY * 0.5f);
	ShapeWidget* _leftBackground = new ShapeWidget(ShapeData(_leftBackgroundPosition,Vector2f(300.0f,750.0f),"green.png"));
	canvas->AddWidget(_leftBackground);	

	for (int _i = 0; _i < 4; _i++)
	{
		const Vector2f& _gap = Vector2f(0.0f, (windowY * 0.175f) * _i);
		InitTroop(_gap, _i);
	}


	const Vector2f& _rightBackgroundPosition = Vector2f(windowX * 0.8f, windowY * 0.5f);
	ShapeWidget* _rightBackground = new ShapeWidget(ShapeData(_rightBackgroundPosition, Vector2f(300.0f, 300.0f), "green.png"));
	canvas->AddWidget(_rightBackground);

	const Vector2f& _initialTroopPosition = Vector2f(_rightBackgroundPosition.x - 75.0f, _rightBackgroundPosition.y - 75.0f);
	for (int _i = 0; _i < 4; _i++)
	{
		const Vector2f& _gap = Vector2f(_i % 2 == 0 ? 150.0f : 0.0f, _i > 1 ? 150.0f : 0.0f) ;
		const Vector2f& _pos = _initialTroopPosition + _gap;
		ShapeWidget* _troopBackground = new ShapeWidget(ShapeData(_pos, Vector2f(125.0f, 125.0f), "red.png"));
		TextWidget* _troopAmoung = new Label(TextData("x0", Vector2f(_pos.x, _pos.y + 40.0f),"Font.ttf",20));
		canvas->AddWidget(_troopBackground);
		canvas->AddWidget(_troopAmoung);
	}
}

void BarrackMenu::InitTroop(const Vector2f& _positionGap,const int _index)
{
	const Vector2f& _backgroundPosition = Vector2f(windowX * 0.225f, windowY * 0.235f) + _positionGap;
	ShapeWidget* _background = new ShapeWidget(ShapeData(_backgroundPosition, Vector2f(250.0f, 150.0f), "red.png"));
	canvas->AddWidget(_background);

	const Vector2f& _troopBackgroundPosition = Vector2f(_backgroundPosition.x - 75.0f, _backgroundPosition.y + 25.0f);
	ShapeWidget* _troopBackground = new ShapeWidget(ShapeData(_troopBackgroundPosition, Vector2f(75.0f, 75.0f), "blue.png"));
	canvas->AddWidget(_troopBackground);

	const Vector2f& _statsBackgroundPosition = Vector2f(_backgroundPosition.x + 50.0f, _backgroundPosition.y + 25.0f);
	ShapeWidget* _statsBackground = new ShapeWidget(ShapeData(_statsBackgroundPosition, Vector2f(120.0f, 75.0f), "blue.png"));
	canvas->AddWidget(_statsBackground);

	const Vector2f& _nameBackgroundPosition = Vector2f(_statsBackgroundPosition.x, _statsBackgroundPosition.y - 68.75f);
	ShapeWidget* _nameBackground = new ShapeWidget(ShapeData(_nameBackgroundPosition, Vector2f(120.0f, 40.0f), "blue.png"));
	canvas->AddWidget(_nameBackground);

	const Vector2f& _buttonPosition = Vector2f(_troopBackgroundPosition.x, _troopBackgroundPosition.y - 68.75f);
	ShapeWidget* _button = new Button(ShapeData(_buttonPosition,Vector2f(75.0f,40.0f),"blue.png"));
	canvas->AddWidget(_button);

	TextWidget* _name = new Label(TextData(data.troops[_index].name, _nameBackgroundPosition, "Font.ttf"));
	canvas->AddWidget(_name);

	TextWidget* _life = new Label(TextData("Health : " + to_string(data.troops[_index].life), Vector2f(_statsBackgroundPosition.x, _statsBackgroundPosition.y - 15.0f), "Font.ttf"));
	canvas->AddWidget(_life);

	TextWidget* _attack = new Label(TextData("Damage : " + to_string(data.troops[_index].damage), Vector2f(_statsBackgroundPosition.x, _statsBackgroundPosition.y + 15.0f), "Font.ttf"));
	canvas->AddWidget(_attack);

	TextWidget* _cost = new Label(TextData("X " + to_string(data.troops[_index].cost), _buttonPosition, "Font.ttf"));
	canvas->AddWidget(_cost);

}
