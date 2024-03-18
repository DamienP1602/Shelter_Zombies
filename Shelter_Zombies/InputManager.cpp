#include "InputManager.h"

void Action::Register()
{
	if (ActionMap* _actionMap = InputManager::GetInstance().Get(actionMap))
	{
		_actionMap->Add(id, this);
		return;
	}
	ActionMap* _newMap = new ActionMap(actionMap);
	_newMap->Add(id, this);
}

void Action::Execute()
{
	if (data.callback)
	{
		data.callback();
	}
}

void ActionMap::Register()
{
	InputManager::GetInstance().Add(id, this);
}

void ActionMap::Update(const Event& _event)
{
	for (const auto& _pair : allValues)
	{
		for (const InputData& _inputData : _pair.second->data.keys)
		{
			if (_event.type == _inputData.type && _event.key.code == _inputData.key)
			{
				_pair.second->Execute();
			}
		}
	}
	GarbageValues();
}

bool InputManager::Update(RenderWindow _window)
{
	Event _event;
	while (_window.pollEvent(_event))
	{
		if (_event.type == Event::Closed)return false;

		UpdateInputs(_event);
	}
	mousePosition = Vector2f(Mouse::getPosition(_window));
	GarbageValues();

	return true;
}

void InputManager::UpdateInputs(const Event& _event)
{
	for (const auto& _pair : allValues)
	{
		_pair.second->Update(_event);
	}
}
