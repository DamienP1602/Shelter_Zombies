#include "PlayerAttackComponent.h"
#include "Game.h"
#include "Enemy.h"
#include "Macro.h"
#include"Game.h"

PlayerAttackComponent::PlayerAttackComponent(Actor* _owner, const int _damages,const int _range) : Component(_owner)
{
	canAttack = true;
	damages = _damages;
	range = _range;
	animation = owner->GetComponent<PlayerAnimationComponent>();
}
