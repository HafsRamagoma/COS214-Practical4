#ifndef SAFETYDECORATOR_H
#define SAFETYDECORATOR_H

#include "TaskDecorator.h"

class SafetyDecorator : TaskDecorator {

private:

	int riskLevel;
	bool compliant;

public:
	SafetyDecorator(FilmComponent* component, int riskLevel);
	
	void request();
};

#endif
