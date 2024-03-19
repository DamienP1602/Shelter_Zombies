#include "InteractionComponent.h"
#include "Player.h"
#include "ActorManager.h"
#include "InteractableActor.h"
#include "Macro.h"

InteractionComponent::InteractionComponent(Actor* _owner) : Component(_owner)
{
	range = 200.0f;
	inventory = dynamic_cast<Player*>(_owner)->GetInventory();
	pnj = nullptr;
}


void InteractionComponent::TryToInteract()
{
	for (InteractableActor* _interactable : ActorManager::GetInstance().GetInteractables())
	{
		const float _distance = Distance(owner->GetShapePosition(), _interactable->GetShapePosition());
		if (_distance > range) 
			continue;
		else if(pnj = dynamic_cast<PNJ*>(_interactable))
		{
			//_interactable->OpenDiscussion();
			pnj->OpenWidget();
			pnj->GetComponent<AnimationComponent>()->RunAnimation("Talk", 1);
		}

		inventory->SetStatus(false);
	}
}

void InteractionComponent::StopInteract()
{
}