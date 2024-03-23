#include "StandbyToChase.h"

StandbyToChase::StandbyToChase(BlackBoard* _blackBoard) : Transition(_blackBoard)
{
}

void StandbyToChase::Init(State* _nextState)
{
	nextState = _nextState;
}

bool StandbyToChase::CanNext() const
{
	return blackBoard->hasTarget && !blackBoard->isInRange;
}
