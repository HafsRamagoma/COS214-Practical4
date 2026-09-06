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

size_t FilmComponent::getChildCount() const {
	return 0;
}

FilmComponent* FilmComponent::getChild(size_t index) const {
	return nullptr;
}

bool FilmComponent::isLeaf() const {
	return true;
}

bool FilmComponent::isCompleted() const {
	return false;
}
