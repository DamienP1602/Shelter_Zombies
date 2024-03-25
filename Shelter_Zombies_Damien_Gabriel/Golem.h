#pragma once
#include "Entity.h"

class Golem : public Entity
{
public:
	Golem(const Vector2f& _position, const int _level);

	void Init() override;
};

