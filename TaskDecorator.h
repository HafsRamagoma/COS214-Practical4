#ifndef TASKDECORATOR_H
#define TASKDECORATOR_H

#include "FilmComponent.h"

class TaskDecorator : public FilmComponent {

public:
	FilmComponent* wrappedComponent;	//decorator can wrap a WorkGroup or TaskItem

	TaskDecorator(FilmComponent* component);

	virtual ~TaskDecorator();

	virtual double getCost() = 0;

	virtual void request() = 0; 	//pure virtual; typically delegates to wrappedComponent->request() plus extra behaviour
};

#endif
