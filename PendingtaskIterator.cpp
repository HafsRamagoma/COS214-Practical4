#include "PendingtaskIterator.h"
#include "FilmComponent.h"

PendingtaskIterator::PendingtaskIterator(FilmComponent* root) {
        filterAndCollect(root);
}

void PendingtaskIterator::filterAndCollect(FilmComponent* component) {
        if(!component) return;

        if(!component->isCompleted()) {
            if(component->isLeaf()){
                pendingList.push_back(component);
            }
        }

        for(size_t i = 0; i < component->getChildCount();i++){
            filterAndCollect(component->getChild(i));
        }
}

void PendingtaskIterator::first() {
    index = 0;
}

void PendingtaskIterator::next() {
    if(!isDone()){
        index++;
    }
}

bool PendingtaskIterator::isDone() const {
    return index >= pendingList.size();
}

FilmComponent* PendingtaskIterator::currentItem() const {
    if(isDone()) return nullptr;
    return pendingList[index];
}

PendingtaskIterator::~PendingtaskIterator() {
    pendingList.clear();
}
