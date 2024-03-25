#include "Transition.h"

Transition::Transition(BlackBoard* _blackBoard)
{
	blackBoard = _blackBoard;
	nextState = nullptr;
}

Transition::~Transition()
{
	blackBoard = nullptr;
	nextState = nullptr;
	delete blackBoard;
	delete nextState;
}
