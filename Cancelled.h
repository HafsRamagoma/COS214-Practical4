#ifndef CANCELLED_H
#define CANCELLED_H

#include "TaskState.h"
#include "TaskItem.h"

class Cancelled : public TaskState {

public:
	Cancelled(TaskItem* task);

	void process();

	std::string getStateName();

	bool isPending();	//overridden: false -- a cancelled task isn't pending, it's dead

	//Terminal Node
};

#endif
