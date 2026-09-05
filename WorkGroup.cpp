#include "WorkGroup.h"
#include <iostream>

WorkGroup::WorkGroup(std::string name) {
	this->name = name;
}

void WorkGroup::add(FilmComponent* component) {
	taskItems.push_back(component);
}

void WorkGroup::remove(FilmComponent* component) {
	for (auto it = taskItems.begin(); it != taskItems.end(); ++it) {
		if (*it == component) {
			taskItems.erase(it);
			break;
		}
	}
}

std::string WorkGroup::getName() {
	return name;
}

double WorkGroup::getCost() {
	double total = 0.0;
	for (FilmComponent* child : taskItems) {
		total += child->getCost();
	}
	return total;
}

void WorkGroup::request() {
	for(FilmComponent* child : taskItems){
		child->request();
	}
}

void WorkGroup::print() {
	std::cout << "Group: " << name << std::endl;
	for (FilmComponent* child : taskItems) {
		child->print();
	}
}

WorkGroup::~WorkGroup() {
	for (FilmComponent* child : taskItems) {
		delete child;
	}
	taskItems.clear();
}

FilmIterator* WorkGroup::createDepthFirstSearchIterator() {
	return nullptr;
}

FilmIterator* WorkGroup::createPendingTaskIterator() {
	return nullptr;
}
