#include "Brain.h"
#include "Entity.h"

Brain::Brain(Actor* _owner) : Component(_owner)
{
	blackBoard = new BlackBoard();
}

Brain::~Brain()
{
	for (size_t i = 0; i < states.size(); i++)
		states[i] = nullptr;
	states.clear();
	blackBoard = nullptr;
	currentState = nullptr;
	delete blackBoard;
	delete currentState;
}

void Brain::Update(const float _deltaTime)
{
	if (!dynamic_cast<Entity*>(owner)->IsActive())
		return;

	currentState->Update(_deltaTime);

	if (Transition* _transition = currentState->GetNextTransition())
	{
		currentState->Stop();
		currentState = _transition->GetNextState();
		currentState->Start();
	}
}