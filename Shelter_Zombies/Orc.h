#pragma once
#include "Entity.h"

class Orc : public Entity
{
public:
	Orc(const Vector2f& _position, const int _level);
	~Orc();
};

