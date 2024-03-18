#include "HUD.h"
#include "InputManager.h"
#include "Widget.h"
#include "Button.h"

void HUD::Interact(const Vector2f& _worldPosition, const Event& _event)
{
	//If interaction with button
	for (Button* _button : buttons)
	{
		if (!_button->IsVisible()) 
			continue;

		if (_button->GetDrawable()->getGlobalBounds().contains(_worldPosition))
		{
			if (_event.type == Event::MouseButtonPressed)
			{
				if (_button->OnPressed())
					return;
			}
			_button->OnHovered();
		}
		else
		{
			_button->OnUnhovered();
		}

		if (_event.type == Event::EventType::MouseButtonReleased)
		{
			_button->OnReleased();
		}

		_button->OnHeld();
	}

	//If interaction with scrollbar
	for (ScrollBar* _scrollBar : scrollBars)
	{
		if (!_scrollBar->IsVisible()) 
			continue;

		if (_event.type == Event::MouseWheelScrolled)
		{
			_scrollBar->UpdateScroll(_event);
		}
	}
}

Button* HUD::GetHoveredButton(const vector<Button*>& _buttons)
{
	const Vector2f& _worldPosition = InputManager::GetInstance().GetWorldPosition();

	for (Button* _button : _buttons)
	{
		if (_button->IsVisible() && _button->GetDrawable()->getGlobalBounds().contains(_worldPosition))
		{
			return _button;
		}
	}

	return nullptr;
}

Button* HUD::GetPressedButton(const vector<Button*>& _buttons)
{
	const Vector2f& _worldPosition = InputManager::GetInstance().GetWorldPosition();

	for (Button* _button : _buttons)
	{
		if (_button->IsVisible() && _button->GetDrawable()->getGlobalBounds().contains(_worldPosition))
		{
			return _button;
		}
	}

	return nullptr;
}
