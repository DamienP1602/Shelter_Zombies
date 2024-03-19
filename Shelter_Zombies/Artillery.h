#pragma once
#include "Entity.h"

class Artillery : public Entity
{
public:
	Artillery(const Vector2f& _position);

protected:
	void Movement() override;
	void Action() override;
};

