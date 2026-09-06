#ifndef PENDINGTASKITERATOR_H
#define PENDINGTASKITERATOR_H

#include "FilmIterator.h"

class PendingtaskIterator : public FilmIterator {

private:
	std::vector<FilmComponent*> pendingList;
	size_t index;

public:
	PendingtaskIterator(FilmComponent* root);

	void filterAndCollect(FilmComponent* component);

	void first() override;

	void next() override;

	bool isDone() override;

	FilmComponent* currentItem() override;

	~PendingtaskIterator();
};

#endif
