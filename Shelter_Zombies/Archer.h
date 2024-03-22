#pragma once
#include "Entity.h"

class Archer : public Entity
{
public:
	Archer(const Vector2f& _position, const int _level);

	void Init() override;
};

