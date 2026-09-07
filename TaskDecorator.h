#ifndef TASKDECORATOR_H
#define TASKDECORATOR_H

#include "FilmComponent.h"

class TaskDecorator : public FilmComponent {

protected:
	FilmComponent* wrappedComponent;	//kept as FilmComponent*, not narrowed -- can wrap either a WorkGroup or a TaskItem

public:
	TaskDecorator(FilmComponent* component);

	virtual ~TaskDecorator();	//deletes wrappedComponent: the decorator now stands in for it in the tree

	std::string getName();		//delegates to wrappedComponent

	virtual double getCost() = 0;	//pure virtual: concrete decorators add their surcharge on top of wrappedComponent->getCost()

	virtual void request() = 0;	//pure virtual: concrete decorators typically delegate then add extra behaviour

	void print();				//delegates to wrappedComponent

	FilmIterator* createDepthFirstIterator();	//delegates to wrappedComponent

	FilmIterator* createPendingTaskIterator();			//delegates to 
	
	size_t getChildCount() const;

	FilmComponent* getChild(size_t index) const;

	bool isLeaf() const;

	bool isCompleted() const;
};

#endif
