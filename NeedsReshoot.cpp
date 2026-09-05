#include "NeedsReshoot.h"
#include "InProgress.h"
#include <iostream>

NeedsReshoot::NeedsReshoot(TaskItem* task) : TaskState(task) {
}

void NeedsReshoot::process() {
	std::cout << task->getName() << ": needs reshoot (attempt #" << task->getReshootCount() << ")." << std::endl;
}

std::string NeedsReshoot::getStateName() {
	return "Needs Reshoot";
}

void NeedsReshoot::start() {
	task->changeState(new InProgress(task));
}
