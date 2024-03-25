#include "StandbyToAttack.h"

StandbyToAttack::StandbyToAttack(BlackBoard* _blackBoard) : Transition(_blackBoard)
{
}

void StandbyToAttack::Init(State* _nextState)
{
	nextState = _nextState;
}

bool StandbyToAttack::CanNext() const
{
	return blackBoard->isInRange;
}
