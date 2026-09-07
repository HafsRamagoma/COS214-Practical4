#include "OvertimeDecorator.h"
#include <iostream>

OvertimeDecorator::OvertimeDecorator(FilmComponent* component)
	: TaskDecorator(component), overtimeRate(500.0) {
}

double OvertimeDecorator::getCost() {
	return wrappedComponent->getCost() + overtimeRate;
}

void OvertimeDecorator::request() {
	wrappedComponent->request();
	std::cout << "[Overtime] " << wrappedComponent->getName()
			  << " incurred an overtime surcharge of R" << overtimeRate << std::endl;
}