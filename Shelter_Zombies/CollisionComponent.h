#pragma once
#include "Component.h"
#include "ShapeObject.h"
#include <functional>

enum CollisionType
{
	CT_NONE = 1,
	CT_CONSTRUCTION,
	CT_WALL,
	CT_ENTITY
};

class CollisionComponent : public Component
{
	ShapeObject* boxCollision;
	CollisionType type;
	CollisionType activeCollision;

public:
	ShapeObject* GetBoxCollision() const
	{
		return boxCollision;
	}
	CollisionType GetType() const
	{
		return type;
	}
	void SetTypeOfCollision(const CollisionType& _type)
	{
		type = _type;
	}

public:
	CollisionComponent(Actor* _owner, const CollisionType& _type,const CollisionType& _activeCollision);
	~CollisionComponent();

public:
	bool CheckCollision(const Vector2f& _position);
	bool CheckCollision(const vector<Actor*>& _ignoredActors = vector<Actor*>());
};