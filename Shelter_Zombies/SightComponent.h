#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Kismet.h"

using namespace sf;

class SightComponent : public Component
{
	bool hasTarget;
	float viewRange;
	HitInfo hitInfo;

public:
	bool HasTarget() const
	{
		return hasTarget;
	}
	HitInfo GetHitInfo() const
	{
		return hitInfo;
	}

public:
	SightComponent(Actor* _owner, const float _viewRange);

public:
	virtual void Update(const float _deltaTime) override;
};