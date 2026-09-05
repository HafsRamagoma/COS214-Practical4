#ifndef OVERTIMEDECORATOR_H
#define OVERTIMEDECORATOR_H

#include "TaskDecorator.h"

class OvertimeDecorator :public TaskDecorator {

	private:
		double overtimeRate;
	public:
		OvertimeDecorator(FilmComponent* component);

		double getCost();	//wrappedComponent->getCost() + overtimeRate

		void request();		//delegates to wrappedComponent->request(), then logs the overtime note
};

#endif
