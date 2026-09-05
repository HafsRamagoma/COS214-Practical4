#include "NotStarted.h"
#include "InProgress.h"
#include "Cancelled.h"
#include <iostream>

NotStarted::NotStarted(TaskItem* task) : TaskState(task) {
}

void NotStarted::process() {
	std::cout << task->getName() << ": not started." << std::endl;
}

std::string NotStarted::getStateName() {
	return "Not Started";
}

void NotStarted::start() {
	task->changeState(new InProgress(task));
}

void NotStarted::cancel() {
	task->changeState(new Cancelled(task));
}
