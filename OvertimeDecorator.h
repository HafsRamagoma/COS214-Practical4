#ifndef OVERTIMEDECORATOR_H
#define OVERTIMEDECORATOR_H

#include "TaskDecorator.h"

class OvertimeDecorator :public TaskDecorator {


public:
	OvertimeDecorator(FilmComponent* component);

	double getCost();

	void overTimeRate();
};

#endif
