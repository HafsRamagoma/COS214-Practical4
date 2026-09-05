#ifndef NOTSTARTED_H
#define NOTSTARTED_H

#include "TaskState.h"
#include "TaskItem.h"

class NotStarted : public TaskState {

public:
	NotStarted(TaskItem* task);

	void process(); 	//reports task hasn't begun, no cost/duration accrual

	std::string getStateName();

	void start();		//NotStarted -> InProgress

	void cancel();		//NotStarted -> Cancelled
};

#endif
