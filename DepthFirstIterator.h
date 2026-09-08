#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "FilmIterator.h"

class DepthFirstIterator : public FilmIterator {

private:
	std::vector<FilmComponent*> snapshot;
	size_t index;

private:

	void populateSnapShot(FilmComponent* component);

public:

    DepthFirstIterator(FilmComponent* root);
	void first();

	void next();

	bool isDone();

	FilmComponent* currentItem();

	~DepthFirstIterator();
};

#endif
