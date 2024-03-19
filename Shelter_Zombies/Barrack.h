#pragma once
#include "Building.h"

class Barrack : public Building
{
public:
	Barrack(const Vector2f& _position);

private:
	void CreateEntity(int _type);
};

