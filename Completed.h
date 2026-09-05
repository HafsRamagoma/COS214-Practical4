#ifndef COMPLETED_H
#define COMPLETED_H

#include "TaskState.h"
#include "TaskItem.h"

class Completed : public TaskState {


	public:
		Completed(TaskItem* task);

		void process();

		std::string getStateName();

		void flagReshoot();	//Completed-> NeedsReshoot (director isn't happy with the take)

		bool isPending();	//overridden: false -- completed work isn't pending
};

#endif
