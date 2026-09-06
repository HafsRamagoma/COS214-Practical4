#include "DepthFirstIterator.h"

DepthFirstIterator::DepthFirstIterator(FilmComponent* root) {
    populateSnapShot(root);
}

void DepthFirstIterator::populateSnapShot(FilmComponent* component) {
    if(!component) return;
    snapshot.push_back(component);
    //only iterated to the root and not its children
    for(size_t i = 0; i < component->getChildCount(); i++){
        populateSnapShot(component->getChild(i));
    }

}

void DepthFirstIterator::first() {
    index = 0;
}

void DepthFirstIterator::next() {
    if(!isDone()){
        index++;
    }
}

bool DepthFirstIterator::isDone() {
    return index >= snapshot.size();
}

FilmComponent* DepthFirstIterator::currentItem() {
    return isDone() ? nullptr : snapshot[index];
}

//added destructor
DepthFirstIterator::~DepthFirstIterator() {
    snapshot.clear();
}
