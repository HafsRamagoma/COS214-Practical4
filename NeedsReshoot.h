#ifndef NEEDSRESHOOT_H
#define NEEDSRESHOOT_H

#include "TaskState.h"
#include "TaskItem.h"

class NeedsReshoot : public TaskState {
	public:
		NeedsReshoot(TaskItem* task);
		
		void process();

		std::string getStateName();

		void start(); //NeedsReshoot transitions back to InProgress
};

#endif
