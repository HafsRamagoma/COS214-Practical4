#ifndef EQUIPMENTDECORATOR_H
#define EQUIPMENTDECORATOR_H

#include "TaskDecorator.h"
#include <string>

class EquipmentDecorator : public TaskDecorator {

private:
	std::string equipmentName;	
	double rentalCost;			//added on top of wrappedComponent->getCost()

public:
	EquipmentDecorator(FilmComponent* component, std::string equipmentName, double rentalCost);

	double getCost();	

	void request();		//delegates to wrappedComponent->request(), then logs the equipment used
};

#endif
