#include "Caretaker.h"

void Caretaker::addMemento(Memento* memento)
{
    mementoList.push_back(memento);
}
Memento * Caretaker::getMemento(std::vector<Memento*>::size_type idx)
{
    if(idx < mementoList.size())
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