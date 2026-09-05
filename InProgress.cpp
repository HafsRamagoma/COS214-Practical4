#include "InProgress.h"
#include "Blocked.h"
#include "Completed.h"
#include "Cancelled.h"
#include <iostream>

InProgress::InProgress(TaskItem* task) : TaskState(task) {
}

void InProgress::process() {
	std::cout << task->getName() << ": in progress." << std::endl;
}

std::string InProgress::getStateName() {
	return "In Progress";
}

void InProgress::block() {
	task->changeState(new Blocked(task));
}

void InProgress::complete() {
	task->changeState(new Completed(task));
}

void InProgress::cancel() {
	task->changeState(new Cancelled(task));
}
