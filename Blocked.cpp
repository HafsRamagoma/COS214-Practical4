#include "Blocked.h"
#include "InProgress.h"
#include "Cancelled.h"
#include <iostream>

Blocked::Blocked(TaskItem* task, std::string reason) : TaskState(task) {
	this->reason = reason;
}

void Blocked::process() {
	std::cout << task->getName() << ": blocked";
	if (!reason.empty()) {
		std::cout << " (" << reason << ")";
	}
	std::cout << " -- not accruing progress." << std::endl;
}

std::string Blocked::getStateName() {
	return "Blocked";
}

void Blocked::resume() {
	task->changeState(new InProgress(task));
}

void Blocked::cancel() {
	task->changeState(new Cancelled(task));
}
