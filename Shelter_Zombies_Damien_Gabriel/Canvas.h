#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "IManagable.h"
#include "Widget.h"

using namespace std;
using namespace sf;

/// <summary>
/// The canvas to draw widgets
/// </summary>>
class Canvas : public IManagable<string>
{
private:
	bool isVisible;
	FloatRect rect;
	vector<Widget*> uiWidgets;
	vector<Widget*> worldWidgets;

public:
	bool GetVisibilityStatus()
	{
		return isVisible;
	}
	void SetVisibilityStatus(const bool _status, const bool _applyToWidgets = true)
	{
		isVisible = _status;

		if (_applyToWidgets)
		{
			for (Widget* _widget : uiWidgets)
			{
				_widget->SetVisible(_status);
			}

			for (Widget* _widget : worldWidgets)
			{
				_widget->SetVisible(_status);
			}
		}
	}
	bool IsVisible() const
	{
		return isVisible;
	}
	FloatRect GetRect() const
	{
		return rect;
	}
	vector<Widget*> GetUiWidgets() const
	{
		return uiWidgets;
	}
	vector<Widget*> GetWorldWidgets() const
	{
		return worldWidgets;
	}
	void RemoveUIWidget(Widget* _widget)
	{
		for (vector<Widget*>::iterator _it = uiWidgets.begin(); _it != uiWidgets.end(); _it++)
		{
			if (*_it == _widget)
			{
				uiWidgets.erase(_it);
				return;
			}
		}
	}

public:
	Canvas(const string& _name, const FloatRect& _rect = FloatRect(0, 0, 1, 1));
	~Canvas();

private:
	virtual void Register() override;

public:
	void AddWidget(Widget* _widget);
};