#include "Caretaker.h"


void Caretaker::addMemento(Memento* memento) {
    mementoList.push_back(memento);
}



Memento * Caretaker::getMemento(int idx) {
    if (idx >= 0 && static_cast<std::vector<Memento*>::size_type>(idx) < mementoList.size()) {
        return mementoList[idx];
    }
    return nullptr;
}



Caretaker::~Caretaker() {
    for (auto memento : mementoList) {
            delete memento;
    }
}

