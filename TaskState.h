#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>
#include <iostream>

class TaskItem; //forward declaration instead since task state only holds a taskitem*

class TaskState {

protected:
	TaskItem* task;		//back reference to the owning task

public:
	TaskState(TaskItem* task);

	virtual ~TaskState();

	virtual void process() = 0;		//defines the state behaviour

	virtual std::string getStateName() = 0; //used by TaskItem::print()

	//All six transitions below default to "reject and log" in the base class.
	//Concrete states override only the transitions that are legal for them.

	virtual void start();

	virtual void block();

	virtual void resume();

	virtual void complete();

	virtual void cancel();

	virtual void flagReshoot();

	//used by PendingTaskIterator so it doesn't compare state name strings
	virtual bool isPending();
};

#endif
