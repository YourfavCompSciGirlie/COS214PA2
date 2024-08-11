#ifndef CARETAKER_H
#define CARETAKER_H

#include <vector>
#include <iostream>

#include "Memento.h"

using namespace std;

class CareTaker {

    private:
        vector<Memento*> mementoList;

    public:
        ~CareTaker();
        void addMemento(Memento* memento);
        Memento* getMemento(int idx);
};

#endif // CARETAKER_H