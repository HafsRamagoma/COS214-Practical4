#ifndef WORKGROUP_H
#define WORKGROUP_H

#include "FilmComponent.h"
#include <string>
#include <vector>

class WorkGroup : public FilmComponent {

private:
	std::vector<FilmComponent*> taskItems;

public:

	WorkGroup(std::string name);

	void add(FilmComponent* component);		//adds onto TaskItems

	void remove(FilmComponent* component);	//erases from TaskItems

	std::string getName();

	//sums getCost() across all taskItems
	double getCost();

	void request();		//delegates request() to every child in TaskItems

	void print();		//prints its own name, then recursively calls print() on every child

	~WorkGroup(); 		//deletes all its owned children

	//return new snapsots
	FilmIterator* createDepthFirstIterator();

	FilmIterator* createPendingTaskIterator();

	size_t getChildCount() const;	//overridden: FilmComponent's default (0) would make every
									//WorkGroup look empty to the iterators

	FilmComponent* getChild(size_t index) const;	//overridden: FilmComponent's default (nullptr)
													//would break traversal into children

	bool isLeaf() const;	//overridden: false -- a WorkGroup is a composite, not a leaf
};

#endif
