#include "Cancelled.h"
#include <iostream>

Cancelled::Cancelled(TaskItem* task) : TaskState(task){}

void Cancelled::process(){
	std::cout << task->getName() << ": cancelled - No further work will be done." <<std::endl;
}

std::string Cancelled::getStateName() {
	return "Cancelled";
}

bool Cancelled::isPending() {
	return false;
}
