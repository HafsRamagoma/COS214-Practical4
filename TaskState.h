#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>
#include <iostream>
#include "TaskItem.h"

class TaskState {

protected:
	TaskItem* task;		//back reference to the owning task

public:
	TaskState(TaskItem* task);

	virtual ~TaskState();

	virtual void process() = 0;		//defines the state behaviour

	virtual std::string getStateName() = 0; //used by TaskItem::print()

	void start();

	void block();

	void resume();

	void complete();

	void cancel();

	void flagReshoot();

	//used by PendingTaskIterator so it doesn't compare state name strings
	bool isPending();
};

#endif
