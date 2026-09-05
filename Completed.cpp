#include "Completed.h"
#include "NeedsReshoot.h"
#include <iostream>

Completed::Completed(TaskItem* task) : TaskState(task) {
}

void Completed::process() {
	std::cout << task->getName() << ": completed." << std::endl;
}

std::string Completed::getStateName() {
	return "Completed";
}

void Completed::flagReshoot() {
	task->incrementReshootCount();
	task->changeState(new NeedsReshoot(task));
}

bool Completed::isPending() {
	return false;
}
