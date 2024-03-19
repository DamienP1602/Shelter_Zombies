#pragma once
#include "Entity.h"

class Fighter : public Entity
{
public:
	Fighter(const Vector2f& _position);

protected:
	void Movement() override;
	void Action() override;
};

