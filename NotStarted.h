#ifndef NOTSTARTED_H
#define NOTSTARTED_H

#include "TaskState.h"

class NotStarted : public TaskState {


public:
	void process(); 	//reports task hasn't begun. no cost/duration accural
};

#endif
