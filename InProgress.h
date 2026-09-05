#ifndef INPROGRESS_H
#define INPROGRESS_H

#include "TaskState.h"
#include "TaskItem.h"

class InProgress : public TaskState {

public:
	InProgress(TaskItem* task);

	void process();

	std::string getStateName();

	void block();		//InProgress -> Blocked

	void complete();	//InProgress -> Completed

	void cancel();		//InProgress -> Cancelled
};

#endif
