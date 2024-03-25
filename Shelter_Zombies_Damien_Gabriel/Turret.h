#pragma once
#include "Construction.h"

class Turret : public Construction
{
public:
	Turret(const Vector2f& _position);
	void Init() override;
};

