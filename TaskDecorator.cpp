#include "TaskDecorator.h"
#include "FilmIterator.h"

TaskDecorator::TaskDecorator(FilmComponent* component) : wrappedComponent(component) {
	name = wrappedComponent->getName();
}

TaskDecorator::~TaskDecorator() {
	delete wrappedComponent;	
}

std::string TaskDecorator::getName() {
	return wrappedComponent->getName();
}

void TaskDecorator::print() {
	wrappedComponent->print();
}

FilmIterator* TaskDecorator::createDepthFirstIterator() {
	return wrappedComponent->createDepthFirstIterator();
}

FilmIterator* TaskDecorator::createPendingTaskIterator() {
	return wrappedComponent->createPendingTaskIterator();
}

size_t TaskDecorator::getChildCount() const {
	return wrappedComponent->getChildCount();
}

FilmComponent* TaskDecorator::getChild(size_t index) const {
	return wrappedComponent->getChild(index);
}

bool TaskDecorator::isLeaf() const {
	return wrappedComponent->isLeaf();
}

bool TaskDecorator::isCompleted() const {
	return wrappedComponent->isCompleted();
}
