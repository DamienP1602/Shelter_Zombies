#include "StandbyToDeath.h"

StandbyToDeath::StandbyToDeath(BlackBoard* _blackBoard) : Transition(_blackBoard)
{
}

void StandbyToDeath::Init(State* _nextState)
{
	nextState = _nextState;
}

bool StandbyToDeath::CanNext() const
{
	return blackBoard->isDead;
}
