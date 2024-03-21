#pragma once
#include "Entity.h"

class Warlock : public Entity
{
public:
	Warlock(const Vector2f& _position, const int _level);
	~Warlock();

	void Init() override;
};

