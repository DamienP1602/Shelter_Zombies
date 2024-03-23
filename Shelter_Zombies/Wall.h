#pragma once
#include "Construction.h"

class Wall : public Construction
{
public:
	Wall(const Vector2f& _position,const int _level = 0,const bool _isAlly = false);

	void Init() override;

	void Update(const float _deltaTime) override;
};

