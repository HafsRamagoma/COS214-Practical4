#include "TaskItem.h"
#include "NotStarted.h"
#include "DepthFirstIterator.h"
#include "PendingtaskIterator.h"
#include <iostream>

TaskItem::TaskItem(std::string name, double cost) {
	this->taskName = name;
	this->taskCost = cost;
	this->currentState = new NotStarted(this);
	this->reshootCount = 0;
}

TaskItem::~TaskItem() {
	delete currentState;
}

std::string TaskItem::getName() {
	return taskName;
}

double TaskItem::getCost() {
	return taskCost;
}

void TaskItem::request() {
	currentState->process();
}

void TaskItem::print() {
	std::cout << taskName << " (cost: " << taskCost << ") - " << currentState->getStateName() << std::endl;
}

FilmIterator* TaskItem::createDepthFirstIterator() {
	return new DepthFirstIterator(this);
}

FilmIterator* TaskItem::createPendingTaskIterator() {
	return new PendingtaskIterator(this);
}

bool TaskItem::isCompleted() const {
	return !currentState->isPending();
}

void TaskItem::changeState(TaskState* newState) {
	if (this->currentState != newState){
		delete this->currentState;
		currentState = newState;
	}
}

int TaskItem::getReshootCount() {
	return this->reshootCount;
}

void TaskItem::incrementReshootCount() {
	reshootCount++;
}

TaskState* TaskItem::getCurrentState() {
	return currentState;
}
