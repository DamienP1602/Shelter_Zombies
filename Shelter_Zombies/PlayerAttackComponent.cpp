#include "PlayerAttackComponent.h"
#include "Game.h"
#include "Enemy.h"
#include "Macro.h"
#include"Game.h"

PlayerAttackComponent::PlayerAttackComponent(Actor* _owner, const int _damages) : Component(_owner)
{
	canAttack = true;
	damages = _damages;
	range = 50.0f;
	animation = owner->GetComponent<PlayerAnimationComponent>();
}


void PlayerAttackComponent::SpecialAttack()
{
	if (!canAttack) return;

	const Vector2f& _ownerPosition = owner->GetShapePosition();
	const vector<Enemy*>& _mobs = RetrieveAllMobsAround<Enemy>(_ownerPosition, 45.0f);
	for (Enemy* _mob : _mobs)
	{
		if (!_mob) continue;
		
		else
		{
			//_mob->GetLife()->TakeDamages(GetDamages());
			//_mob->GetLife()->SetLife(0);
			//_mob->GetLife()->SetLife(0);
			//_mob->Death();
			//Game::GetPlayer()->GetStats()->UseMana(10.0f);
		}
	}

	const vector<Enemy*>& _mobss = RetrieveAllMobsAround<Enemy>(_ownerPosition, -45.0f);
	for (Enemy* _mob : _mobss)
	{
		if (!_mob) continue;

		else
		{
			//_mob->GetLife()->TakeDamages(GetDamages());
			//_mob->GetLife()->SetLife(0);
			//_mob->GetLife()->SetLife(0);
			//_mob->Death();
			//Game::GetPlayer()->GetStats()->UseMana(1.0f);
		}
	}

	animation->GetCurrentAnimation()->RunAnimation("Special", owner->GetDrawable()->getScale().x);
}