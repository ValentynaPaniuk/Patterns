#pragma once
#include "Coffemachine.h"
class Coffemachine;

class Espresso : public Coffemachine
{
public:
	Espresso();
	~Espresso();

	virtual void MakingCoffee();

};

