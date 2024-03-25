#include "InteractableActor.h"
#include "Game.h"
#include "Widget.h"
#include "Label.h"
#include "Macro.h"

#define FONT "Font.ttf"

InteractableActor::InteractableActor(const string& _name, const ShapeData& _data, Canvas* _canvas) :
	Actor(_name, _data, CT_CONSTRUCTION)
{
	canvas = _canvas;
	isOpen = false;
	interactionBG = nullptr;

	Init();
	Register();
}

InteractableActor::~InteractableActor()
{
	canvas = nullptr;
	interactionBG = nullptr;
}

void InteractableActor::Register()
{
	ActorManager::GetInstance().AddInteractable(this);
}

void InteractableActor::Verify()
{
	if (!interactionBG) 
		return;

	Player* _player = Game::GetPlayer();
	FloatRect _rectPNJ = shape->getGlobalBounds();

	if (_rectPNJ.intersects(_player->GetBounds()))
		if (!isOpen)
			interactionBG->SetVisible(true);
	else
		CloseWidget();
}

void InteractableActor::CloseWidget()
{
	isOpen = false;
	interactionBG->SetVisible(false);
}

void InteractableActor::Init()
{
	const Vector2f& _interactionBGPos = GetShapePosition();
	const RenderWindow& _window = Game::GetWindow();
	const Vector2f& _interactionBGPos2 = _window.mapPixelToCoords(static_cast<Vector2i>(_interactionBGPos));

	//interactionBG = new ShapeWidget(ShapeData(_interactionBGPos, Vector2f(200.0f, 124.0f), PATH_INTERACTION), WT_WORLD);
	//interactionBG->SetVisible(false);
	//canvas->AddWidget(interactionBG);

	const Vector2f& _halfWindowSize = Game::GetWindowSize() / 2.0f;
	const Vector2f& _discussionPos = Vector2f(_halfWindowSize.x, 80.0f);
}

void InteractableActor::Update(const float _deltaTime)
{
	Actor::Update(_deltaTime);
	Verify();
}

void InteractableActor::OpenWidget()
{
	if (isOpen)
	{
		CloseWidget();
		return;
	}

	isOpen = true;
	interactionBG->SetVisible(false);
}