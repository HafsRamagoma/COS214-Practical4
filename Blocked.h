#ifndef BLOCKED_H
#define BLOCKED_H

#include "TaskState.h"
#include "TaskItem.h"
#include <string>

class Blocked : public TaskState {

private:
	std::string reason;	//why it's blocked -- weather, equipment failure, crew availability, etc.

public:
	Blocked(TaskItem* task, std::string reason = "");

	void process();		//logs the block reason; does NOT advance any cost/duration accrual

	std::string getStateName();

	void resume();		//Blocked-> InProgress

	void cancel();		//Blocked-> Cancelled
};


#endif
