#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <string>

#include "Singleton.h"
#include "IManagable.h"
#include "IManager.h"
#include "Macro.h"


using namespace std;
using namespace sf;

typedef Event::EventType ActionType;

struct InputData
{
	ActionType type;
	int key;
};

struct ActionData
{
	string name;
	vector<InputData> keys;
	function<void()> callback;

	ActionData()
	{
		name = "Unknown";
		callback = function<void()>();
	}

	template <class Class, typename RType = void, typename... Args>
	ActionData(const string& _name, Class* _owner, RType(Class::* _callback)(Args...),
		const InputData& _primaryKey, const InputData& _secondaryKey = InputData(), Args... _args)
	{
		name = _name;
		keys.push_back(_primaryKey);
		keys.push_back(_secondaryKey);
		callback = [_owner, _callback, _args...]() {
			return (_owner->*_callback)(_args...);
		};
	}
	ActionData(const string& _name, const function<void()>& _callback, const InputData& _primaryKey, const InputData& _secondaryKey = InputData())
	{
		name = _name;
		keys.push_back(_primaryKey);
		keys.push_back(_secondaryKey);
		callback = _callback;
	}

	bool operator !()const
	{
		return name == "Unknown";
	}
};

struct Action : public IManagable<string>
{
	ActionData data;
	string actionMap;

	Action(const ActionData& _data, const string& _actionMap) : IManagable(_data.name)
	{
		if (!_data)
		{
			toRemove = true;
		}
		data = _data;
		actionMap = _actionMap;
		Register();
	}

public:
	virtual void Register() override;
	void Execute();
};

struct ActionMap : public IManager<string, Action>, public IManagable<string>
{
	vector<Action*> actions;

	ActionMap(const string& _name, const vector<ActionData>& _actionsData = vector<ActionData>()) : IManagable(S_APPEND(_name))
	{
		Register();

		for (const ActionData& _actionData : _actionsData)
		{
			actions.push_back(new Action(_actionData, id));
		}
	}
public:
	vector<Action*> GetAllActions()
	{
		return actions;
	}

private:
	virtual void Register() override;

public:
	void Update(const Event& _event);
};

class InputManager : public Singleton<InputManager>, public IManager<string, ActionMap>
{
	Vector2f mousePosition;

public:
	Vector2f& GetMousePosition()
	{
		return mousePosition;
	}
	void ResetAllCallback()
	{
		for (ActionMap* _actionMap : InputManager::GetInstance().GetAllValues())
		{
			for (Action* _action : _actionMap->GetAllActions())
			{
				_action->data = ActionData();
				_action->SetToRemove(true);
			}
			_actionMap->SetToRemove(true);
		}
	}

public:
	bool Update(RenderWindow _window);

private:
	void UpdateInputs(const Event& _event);
};