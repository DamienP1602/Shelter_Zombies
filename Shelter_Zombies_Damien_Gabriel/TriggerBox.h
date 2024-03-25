#pragma once
#include "Actor.h"

/// <summary>
/// A box trigger by the Player.
/// </summary>
class TriggerBox : public Actor
{
	FloatRect boxRect;
	function<void()> callback;

public:
	TriggerBox(const ShapeData& _data, const function<void()>& _callback);

private:
	void TryToTrigger();

public:
	virtual void Init() override;
	virtual void Update(const float _deltaTime) override;
};