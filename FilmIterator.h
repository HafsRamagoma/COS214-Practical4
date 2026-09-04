#ifndef FILMITERATOR_H
#define FILMITERATOR_H

#include <vector>
#include "WorkGroup.h"

class FilmIterator {


public:
	virtual ~FilmIterator();

	void first();

	void next();

	bool isDone();

	FilmComponent* currentItem();
};

#endif
