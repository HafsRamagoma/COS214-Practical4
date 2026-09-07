#include "EquipmentDecorator.h"
#include <iostream>

EquipmentDecorator::EquipmentDecorator(FilmComponent* component, std::string equipmentName, double rentalCost)
	: TaskDecorator(component), equipmentName(equipmentName), rentalCost(rentalCost) {
}

double EquipmentDecorator::getCost() {
	return wrappedComponent->getCost() + rentalCost;
}

void EquipmentDecorator::request() {
	wrappedComponent->request();
	std::cout << "[Equipment] " << wrappedComponent->getName()
			  << " uses " << equipmentName << " (R" << rentalCost << ")" << std::endl;
}
