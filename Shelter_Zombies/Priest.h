#pragma once
#include "Entity.h"

class Priest : public Entity
{
public:
	Priest(const Vector2f& _position, const int _level);
	~Priest();

	void Init() override;
};

