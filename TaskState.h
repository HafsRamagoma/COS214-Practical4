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

	virtual void process();		//defines the state behaviour

	virtual std::string getStateName() = 0; //used by TaskItem::print()

	//All six transitions below default to "reject and log" in the base class.
	//Concrete states override only the transitions that are legal for them.

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
