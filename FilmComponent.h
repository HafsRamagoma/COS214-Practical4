#ifndef FILMCOMPONENT_H
#define FILMCOMPONENT_H

#include <string>
#include "FilmIterator.h"

class FilmComponent {

protected:
	std::string name;

public:
	FilmComponent();

	virtual void add(FilmComponent* component);

	virtual void remove(FilmComponent* component);

	virtual std::string getName();

	virtual double getCost() = 0;	//cost accumulation point for Decorator

	virtual void request() = 0;		//does the work

	virtual void print() = 0;

	virtual ~FilmComponent();

	virtual FilmIterator* createDepthFirstSearchIterator() = 0;

	virtual FilmIterator* createPendingTaskIterator() = 0;
};

#endif
