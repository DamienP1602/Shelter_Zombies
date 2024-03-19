#pragma once
#include "Actor.h"
#include "Menu.h"
#include "ShapeWidget.h"
#include "Label.h"
#include "ProgressLabel.h"

/// <summary>
/// An actor interactable by the player.
/// Draw a widget if interaction;
/// </summary>
class InteractableActor : public Actor
{
protected:
	Canvas* canvas = nullptr;
	bool isOpen = false;
	ShapeWidget* interactionBG = nullptr;

public:
	InteractableActor(const string& _name, const ShapeData& _data, Canvas* _canvas = nullptr);
	~InteractableActor();

	void SetIsOpen(const bool _status)
	{
		isOpen = _status;
	}
	void SetCanvas(Canvas* _canvas)
	{
		canvas = _canvas;
	}
	virtual void Init() override;
	virtual void Update(const float _deltaTime);
	virtual void OpenWidget();
	virtual void CloseWidget();

private:
	virtual void Register() override;
	void Verify();
};