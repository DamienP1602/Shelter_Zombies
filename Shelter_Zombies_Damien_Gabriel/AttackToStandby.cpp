#include "AttackToStandby.h"

AttackToStandby::AttackToStandby(BlackBoard* _blackBoard) : Transition(_blackBoard)
{

}

void AttackToStandby::Init(State* _nextState)
{
    nextState = _nextState;
}

bool AttackToStandby::CanNext() const
{
    return !blackBoard->hasTarget;
}
