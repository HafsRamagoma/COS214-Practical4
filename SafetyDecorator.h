#ifndef SAFETYDECORATOR_H
#define SAFETYDECORATOR_H

#include "TaskDecorator.h"
#include <string>

class SafetyDecorator : TaskDecorator {

private:

	int riskLevel;
	bool compliant;

public:
	SafetyDecorator(FilmComponent* component, int riskLevel);
	
	double getCost();

	void request();		//performs a compliance check, sets compliant, then delegates
};

#endif
