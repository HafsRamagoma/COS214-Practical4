#include "WorkGroup.h"
#include <iostream>
#include "DepthFirstIterator.h"
#include "PendingtaskIterator.h"


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

FilmIterator* WorkGroup::createDepthFirstIterator() {
	return new DepthFirstIterator(this);
}

FilmIterator* WorkGroup::createPendingTaskIterator() {
	return new PendingtaskIterator(this);
}

size_t WorkGroup::getChildCount() const {
	return taskItems.size();
}

FilmComponent* WorkGroup::getChild(size_t index) const {
	if (index < taskItems.size()) {
		return taskItems[index];
	}
	return nullptr;
}

bool WorkGroup::isLeaf() const {
	return false;
}

