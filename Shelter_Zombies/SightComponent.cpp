#include "SightComponent.h"
#include "Actor.h"
#include "Player.h"
#include "Macro.h"
#include "Enemy.h"

SightComponent::SightComponent(Actor* _owner, const float _viewRange) : Component(_owner)
{
	hasTarget = false;
	viewRange = _viewRange;
	hitInfo = HitInfo();
}

void SightComponent::Update(const float _deltaTime)
{
	const bool _hasHit = Raycast(owner->GetShapePosition(), owner->GetDrawable()->getScale(), viewRange, hitInfo, { owner });
	hasTarget = _hasHit && dynamic_cast<Player*>(hitInfo.actor);
}