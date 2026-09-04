#ifndef TASKITEM_H
#define TASKITEM_H

#include "FilmComponent.h"
#include "TaskState.h"
#include <string>
#include <vector>

class TaskItem : public FilmComponent {

private:
	std::string taskName;
	double taskCost;
	TaskState* currentState;	//current lifecycle state owned by this TaskItem
	int reshootCount = 0;		//increments each time flagReshoot() succeeds, defaulted to 0

public:
	TaskItem(std::string name, double cost);

	~TaskItem();

	std::string getName();

	double getCost();			//base cost, before any Decorator wrapping

	void request();				//delegates to currentState->process()

	void print();				//outputs taskName, taskCost and current state's name

	FilmIterator* createDepthFirstSearchIterator();  //returns a trivial single element iterator over itself

	FilmIterator* createPendingTaskIterator();  //returns a trivial iterator, empty unless this task is itself pending

	void changeState(TaskState* newState);     //delete old state -> assign new state

	int getReshootCount();

	void incrementReshootCount();	//called by NeedsReshoot on entry
};

#endif
