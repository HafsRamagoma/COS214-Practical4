#ifndef WORKGROUP_H
#define WORKGROUP_H

#include "FilmComponent.h"
#include <string>
#include <vector>

class WorkGroup : public FilmComponent {

public:
	std::vector<FilmComponent*> taskItems;

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
	FilmIterator* createDepthFirstSearchIterator();

	FilmIterator* createPendingTaskIterator();
};

#endif
