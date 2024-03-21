#include "PlayerAttackComponent.h"
#include "Game.h"
#include "Enemy.h"
#include "Macro.h"
#include"Game.h"

PlayerAttackComponent::PlayerAttackComponent(Actor* _owner, const int _damages,const float _range) : EntityAttackComponent(_owner,_damages,1,_range)
{
	animation = owner->GetComponent<PlayerAnimationComponent>();
}
