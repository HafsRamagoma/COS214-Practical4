#ifndef PENDINGTASKITERATOR_H
#define PENDINGTASKITERATOR_H

#include "FilmIterator.h"

class PendingtaskIterator : public FilmIterator {

private:
	std::vector<FilmComponent*> pendingList;
	int index;

public:
	PendingtaskIterator(FilmComponent* root);

	void filterAndCollect(FilmComponent* component);

	void first();

	void next();

	bool isDone();

	FilmComponent* currentItem();
};

#endif
