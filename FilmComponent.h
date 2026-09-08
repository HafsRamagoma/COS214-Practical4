#ifndef FILMCOMPONENT_H
#define FILMCOMPONENT_H

#include <string>

class FilmIterator;

class FilmComponent {

protected:
	std::string name;

public:
	FilmComponent();

	virtual void add(FilmComponent*);

	virtual void remove(FilmComponent*);

	virtual std::string getName();

	virtual double getCost() = 0;	//cost accumulation point for Decorator

	virtual void request() = 0;		//does the work

	virtual void print() = 0;

	virtual ~FilmComponent();

	virtual FilmIterator* createDepthFirstIterator() = 0;

	virtual FilmIterator* createPendingTaskIterator() = 0;

	virtual size_t getChildCount() const;

	virtual FilmComponent* getChild(size_t) const;

	virtual bool isLeaf() const;

	virtual bool isCompleted() const;
};

#endif
