#include "Kismet.h"
#include "Actor.h"
#include "ActorManager.h"

bool Raycast(const Vector2f& _origin, const Vector2f& _direction, const float _maxDistance,
	HitInfo& _hitInfo, const vector<Actor*>& _ignoredActors, const float _precision)
{
	if (_direction == Vector2f()) return false;

	Vector2f _currentPosition = _origin;
	float _distance = 0.0f;

	while (Distance(_origin, _currentPosition) < _maxDistance)
	{
		for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
		{
			if (Contains(_actor, _ignoredActors)) continue;

			if (_actor->GetComponent<CollisionComponent>()->CheckCollision(_currentPosition))
			{
				_hitInfo.position = _currentPosition;
				_hitInfo.distance = _distance * 100.0f;
				_hitInfo.actor = _actor;

				return true;
			}
		}

		_distance += _precision;
		_currentPosition += _direction * _distance;
	}

	return false;
}

bool CircleCast(const Vector2f& _origin, const float _radius, Actor*& _target, bool& _isInRange, const vector<Actor*>& _ignoredActors)
{
	Shape* _circleShape = new CircleShape(_radius * 20.0f);
	_circleShape->setPosition(_origin);

	for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	{
		if (_actor->IsAlly())
		{
			continue;
		}

		if (Contains(_actor, _ignoredActors)) continue;

		if (_circleShape->getGlobalBounds().intersects(_actor->GetDrawable()->getGlobalBounds()))
		{
			//cout << "RADIUS " << endl;
			if (!_target) _target = _actor;
			_isInRange = true;
			return true;
		}
	}
	_isInRange = false;
	return false;
}

vector<HitInfo> RaycastAll(const Vector2f& _origin, const Vector2f& _direction, const float _maxDistance,
	const vector<Shape*>& _ignoredShapes, const float _precision)
{
	vector<HitInfo> _hitInfos;
	if (_direction == Vector2f()) return _hitInfos;

	Vector2f _currentPosition = _origin;
	float _distance = 0.0f;

	while (Distance(_origin, _currentPosition) < _maxDistance)
	{
		for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
		{
			//if (_actor->IsAlly()) return _hitInfos;

			Shape* _shape = _actor->GetDrawable();
			if (Contains(_shape, _ignoredShapes)) continue;

			if (_shape->getGlobalBounds().contains(_currentPosition))
			{
				HitInfo _hitInfo;
				_hitInfo.position = _currentPosition;
				_hitInfo.distance = _distance;
				_hitInfo.actor = _actor;

				_hitInfos.push_back(_hitInfo);
			}
		}

		_distance += _precision;
		_currentPosition += _direction * _distance;
	}

	return _hitInfos;
}

bool BoxCast(const FloatRect& _boxRect, HitInfo& _hitInfo, const vector<Actor*>& _ignoredActors)
{
	for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	{
		if (Contains(_actor, _ignoredActors))
			continue;

		if (_boxRect.intersects(_actor->GetDrawable()->getGlobalBounds()))
		{
			_hitInfo.position = _actor->GetShapePosition();
			_hitInfo.distance = Distance(_hitInfo.position, _boxRect.getPosition());
			_hitInfo.actor = _actor;

			return true;
		}
	}

	return false;
}
