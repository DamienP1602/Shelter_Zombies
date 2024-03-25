#pragma once
#include "Transition.h"

class AttackToStandby : public Transition
{
public:
	AttackToStandby(BlackBoard* _blackBoard);

public:
	virtual void Init(State* _nextState) override;
	virtual bool CanNext() const override;
};

