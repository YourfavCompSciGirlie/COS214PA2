#ifndef CARETAKER_H
#define CARETAKER_H

#include <vector>
#include <iostream>

#include "Memento.h"

using namespace std;

class Caretaker {

    private:
        vector<Memento*> mementoList;

    public:
        ~Caretaker();
        void addMemento(Memento* memento);
        Memento* getMemento(int idx);
        
        // Still need to check this
        Memento* restoreState();
};

#endif // CARETAKER_H