#include "Caretaker.h"

void Caretaker::addMemento(Memento* memento)
{
    mementoList.push_back(memento);
}
Memento * Caretaker::getMemento(int idx)
{
    if(static_cast<std::vector<Memento*>::size_type>(idx) < mementoList.size())
    {
        return mementoList[idx];
    }
    return nullptr;
}
Caretaker::~Caretaker()
{
    for(Memento * it : mementoList)
    {
        delete it;
    }
}

// Need to check this
Memento* Caretaker::restoreState() {
    if (!mementoList.empty()) {
        Memento* memento = mementoList.back();
        mementoList.pop_back();
        return memento;
    }
    return nullptr;
}
