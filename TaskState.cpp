#include "TaskState.h"

TaskState::TaskState(TaskItem* task) {
	this->task = task;
}

TaskState::~TaskState(){}


void TaskState::start() {
	std::cout << "Invalid transition: start() called from " << getStateName() << std::endl;
}

void TaskState::block() {
	std::cout << "Invalid transition: block() called from " << getStateName() << std::endl;
}

void TaskState::resume() {
	std::cout << "Invalid transition: resume() called from " << getStateName() << std::endl;
}

void TaskState::complete() {
	std::cout << "Invalid transition: complete() called from " << getStateName() << std::endl;
}

void TaskState::cancel() {
	std::cout << "Invalid transition: cancel() called from " << getStateName() << std::endl;
}

void TaskState::flagReshoot() {
	std::cout << "Invalid transition: flagReshoot() called from " << getStateName() << std::endl;
}

bool TaskState::isPending() {
	return true;
}
