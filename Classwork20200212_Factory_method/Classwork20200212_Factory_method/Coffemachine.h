#pragma once
class Coffemachine
{
	Coffemachine *pCoffemachine;

public:
	Coffemachine();
	~Coffemachine();
	virtual void MakingCoffee() = 0;
	

};

