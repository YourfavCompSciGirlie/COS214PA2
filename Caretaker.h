#ifndef CARETAKER_H
#define CARETAKER_H

#include <vector>
#include "Memento.h"
#include <iostream>
using namespace std;

class Caretaker
{
    private:
        vector<Memento*> mementoList;

    public:
        void addMemento(Memento* memento);
        Memento * getMemento(int idx);
        ~Caretaker();
};

#endif