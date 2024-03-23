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
	Canvas* canvas;
	bool isOpen;
	ShapeWidget* interactionBG;

public:
	InteractableActor(const string& _name, const ShapeData& _data, Canvas* _canvas = new Canvas("InteractableActor"));
	~InteractableActor();

	void SetIsOpen(const bool _status)
	{
		isOpen = _status;
	}
	void SetCanvas(Canvas* _canvas)
	{
		canvas = _canvas;
	}
	virtual int GetCost() = 0;
	virtual void Init() override;
	virtual void Update(const float _deltaTime);
	virtual void OpenWidget();
	virtual void CloseWidget();

private:
	virtual void Register() override;
protected:
	void Verify();
};