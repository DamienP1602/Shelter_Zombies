#pragma once
#include "Transition.h"

class StandbyToAttack : public Transition
{
public:
	StandbyToAttack(BlackBoard* _blackBoard);

public:
	virtual void Init(State* _nextState) override;
	virtual bool CanNext() const override;
};

