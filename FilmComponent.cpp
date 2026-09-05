#include "FilmComponent.h"

FilmComponent::FilmComponent() {
	this->name = "";
}

FilmComponent::~FilmComponent() {
	// Nothing owned directly at this level; subclasses (WorkGroup, TaskDecorator)
	// are responsible for deleting whatever they own.
}

void FilmComponent::add(FilmComponent* component) {
	// Default: do nothing. A leaf (or any component that doesn't manage children)
	// simply ignores an attempt to add a child, rather than crashing.
}

void FilmComponent::remove(FilmComponent* component) {
	// Default: do nothing
}

std::string FilmComponent::getName() {
	return name;
}