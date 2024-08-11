#include "CareTaker.h"


void CareTaker::addMemento(Memento* memento) {
    mementoList.push_back(memento);
}



Memento * CareTaker::getMemento(int idx) {
    if (idx >= 0 && static_cast<std::vector<Memento*>::size_type>(idx) < mementoList.size()) {
        return mementoList[idx];
    }
    return nullptr;
}



CareTaker::~CareTaker() {
    for (auto memento : mementoList) {
            delete memento;
    }
}

