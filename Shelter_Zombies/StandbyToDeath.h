#pragma once
#include "Transition.h"

class StandbyToDeath : public Transition
{
public:
	StandbyToDeath(BlackBoard* _blackBoard);

public:
	virtual void Init(State* _nextState) override;
	virtual bool CanNext() const override;
};
