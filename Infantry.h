#ifndef INFANTRY_H
#define INFANTRY_H
#include <iostream>
using namespace std;

#include "Soldiers.h"
class Soldiers;

class Infantry : public Soldiers
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
        Soldiers* clonis();

        //void engage();
        //void disengage();
};

#endif