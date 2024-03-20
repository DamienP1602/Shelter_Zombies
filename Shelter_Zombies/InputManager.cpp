#include "InputManager.h"
#include "HUD.h"

bool InputManager::Update(RenderWindow& _window)
{
	const Vector2i& _mousePosition = Mouse::getPosition(_window);
	mousePosition = Vector2f(_mousePosition);
	worldPosition = _window.mapPixelToCoords(_mousePosition);

	Event _event;
	while (_window.pollEvent(_event))
	{
		if (_event.type == Event::Closed) return false;
		if (_event.type == Event::Resized)
		{
			//
			const FloatRect _visibleArea(0.0f, 0.0f, static_cast<float>(_event.size.width), static_cast<float>(_event.size.height));
			 //const FloatRect _visibleArea(0.0f, 0.0f,0.0f, 0.0f);
			_window.setView(View(_visibleArea));
			cout << "resized" << endl;
		}
		//HUD::GetInstance().Interact(worldPosition, _event.type);
		HUD::GetInstance().Interact(worldPosition, _event);
		UpdateInputs(_event);
	}

	GarbageValues();

	return true;
}

void InputManager::UpdateInputs(const Event& _event)
{
	for (const auto& _pair : allValues)
	{
		if (_pair.second->isActive)
		{
			_pair.second->Update(_event);
		}
	}
}