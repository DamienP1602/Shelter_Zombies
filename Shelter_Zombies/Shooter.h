#pragma once
#include "Entity.h"

class Shooter : public Entity
{
public:
	Shooter(const Vector2f& _position);

protected:
	void Movement() override;
	void Action() override;
};

