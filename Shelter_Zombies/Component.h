#pragma once

class Actor;

class Component
{
protected:
	Actor* owner;

public:
	Actor* GetOwner() { return owner; }

public:
	Component(Actor* _owner);
	~Component();

public:
	virtual void Init() { };
	virtual void Update(const float _deltaTime) { };
};