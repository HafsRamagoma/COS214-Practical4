#ifndef BLOCKED_H
#define BLOCKED_H

#include "TaskState.h"

class Blocked : public TaskState {

public:
	std::string reason;

	void process();

	Blocked(TaskItem* task, std::string reason = "");
};

#endif
