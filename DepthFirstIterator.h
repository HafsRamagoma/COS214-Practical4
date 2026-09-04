#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "FilmIterator.h"

class DepthFirstIterator : public FilmIterator {

private:
	std::vector<FilmComponent*> snapshot;
	int index;

private:
	DepthFirstIterator(FilmComponent* root);

	void populateSnapShot(FilmComponent* component);

public:
	void first();

	void next();

	bool isDone();

	FilmComponent* currentItem();
};

#endif
