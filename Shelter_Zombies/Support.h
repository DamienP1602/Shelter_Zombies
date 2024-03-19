#pragma once
#include "Entity.h"

class Support : public Entity
{
public:
	Support(const Vector2f& _position);

protected:
	void Movement() override;
	void Action() override;
};

