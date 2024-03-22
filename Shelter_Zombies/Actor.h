#pragma once
#include "ShapeObject.h"
#include "IManagable.h"
#include "CollisionComponent.h"
#include "AnimationComponent.h"

using namespace std;

class Actor : public ShapeObject, public IManagable<string>
{
protected:
	int layer = 0;
	vector<Component*> components;
	CollisionComponent* collision;
	AnimationComponent* animation;

public:
	Actor(const string& _name, const ShapeData& _data, const CollisionType& _collisionType = CT_NONE, const CollisionType& _activeCollision = CT_NONE);
	~Actor();

	template <typename T>
	T* GetComponent() const
	{
		for (Component* _currentComponent : components)
		{
			if (T* _component = dynamic_cast<T*>(_currentComponent))
			{
				return _component;
			}
		}

		return nullptr;
	}
	FloatRect GetBounds() const
	{
		return shape->getGlobalBounds();
	}
	int GetLayer() const
	{
		return layer;
	}

protected:
	virtual void Register() override;

public:
	virtual void Init();
	virtual void Update(const float _deltaTime);
	void Destroy(const float _waitingTime = 0.0f);
	void InitAnimations(const vector<AnimationData>& _animations);
};