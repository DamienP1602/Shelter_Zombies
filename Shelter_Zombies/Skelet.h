#pragma once
#include "Entity.h"

class Skelet : public Entity
{
public:
	Skelet(const Vector2f& _position, const int _level);

	void Init() override;
};
