#pragma once
#include "Actor.h"

/// <summary>
/// A blocking decor in game
/// Update if player/enemy controled map?
/// </summary>
class Decor : public Actor
{
public:
	Decor(const ShapeData& _shape);
	~Decor();
};
