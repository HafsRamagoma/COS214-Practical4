#ifndef CANCELLED_H
#define CANCELLED_H

#include "TaskState.h"

class Cancelled :public TaskState {


public:
	void process();
};

#endif
