#pragma once
#include "Transition.h"

class StandbyToChase : public Transition
{
public:
	StandbyToChase(BlackBoard* _blackBoard);

public:
	virtual void Init(State* _nextState) override;
	virtual bool CanNext() const override;
};

