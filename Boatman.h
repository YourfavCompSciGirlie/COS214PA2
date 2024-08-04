#ifndef BOATMAN_H
#define BOATMAN_H
#include <iostream>
using namespace std;

#include "Soldiers.h"
class Soldiers;


class Boatman : public Soldiers
{
    private: 
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldierPerUnit;
        string unitName;
                
        //methods which are private

        void prepare();
        void execute();
        void retreat();
        void rest();

    public:

        // Function for 4.2. Prototype (clone - making a copy of itself)
        // Implementation made virtual (different from the UML)
        virtual Soldiers* clonis();
};

#endif