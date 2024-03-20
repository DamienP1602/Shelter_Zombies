#pragma once
#include "IManagable.h"
#include "Canvas.h"
#include "ShapeWidget.h"
#include "Button.h"
#include "Label.h"
#include "SoundData.h"

//TODO Menu change paths
#define PATH_BACKGROUND "UIs/Menus/Background.png"
#define PATH_TITLE_ICON "UIs/Menus/TitleBarMenu.png"
#define FONT "Font.ttf"

/// <summary>
/// A menu of the game
/// </summary>
class Menu : public IManagable<string>
{
	bool isInit;
	SoundData* sound;

protected:
	float windowX;
	float windowY;

	Canvas* canvas;
	Button* backButton;
	Menu* owner;

public:
	/// <summary>
	/// Allow to hide or display menu and there widget
	/// </summary>
	/// <param name="_status"></param>
	/// <param name="_applyToWidgets"></param>
	virtual void SetStatus(const bool _status, const bool _applyToWidgets = true)
	{
		if (!isInit)
		{
			Init();			
		}
		canvas->SetVisibilityStatus(_status, _applyToWidgets);
	}
	void SetOwner(Menu* _owner)
	{
		owner = _owner;
	}
	bool IsActive() const
	{
		return isInit && canvas->GetVisibilityStatus();
	}
	Canvas* GetCanvas() const
	{
		return canvas;
	}

public:
	Menu(const string& _name, Menu* _owner = nullptr);

	virtual void Init();
	void BackButton();

private:
	virtual void Register() override;
};