#ifndef FILMITERATOR_H
#define FILMITERATOR_H

#include <vector>
#include "WorkGroup.h"

class FilmIterator {


//Iterator is pure virtual, interface only
public:
	virtual ~FilmIterator();

	virtual void first() = 0;

	virtual void next() = 0;

	virtual bool isDone() = 0;

	virtual FilmComponent* currentItem() = 0;
};

#endif
