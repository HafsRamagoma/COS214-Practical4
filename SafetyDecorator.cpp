#include "SafetyDecorator.h"
#include <iostream>

SafetyDecorator::SafetyDecorator(FilmComponent* component, int riskLevel)
	: TaskDecorator(component), riskLevel(riskLevel), compliant(false) {
}

double SafetyDecorator::getCost() {
	//higher risk work needs more safety equipment/insurance cover
	return wrappedComponent->getCost() + (riskLevel * 100.0);
}

void SafetyDecorator::request() {
	//simple compliance rule: anything above a moderate risk threshold needs sign-off
	compliant = (riskLevel <= 5);

	if (compliant) {
		std::cout << "[Safety] " << wrappedComponent->getName()
				  << " passed compliance check (risk level " << riskLevel << ")" << std::endl;
	} else {
		std::cout << "[Safety] WARNING: " << wrappedComponent->getName()
				  << " exceeds safe risk threshold (risk level " << riskLevel << ")" << std::endl;
	}

	wrappedComponent->request();
}