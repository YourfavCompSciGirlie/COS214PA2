#ifndef SOLDIERS_H
#define SOLDIERS_H
#include <iostream>
using namespace std;

#include "Memento.h"

class Soldiers{

    private: 
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldierPerUnit;
        string unitName;

        // methods

        virtual void prepare() = 0;
        virtual void execute() = 0;
        virtual void retreat() = 0;
        virtual void rest() = 0;
        

    public:
        virtual Soldiers* clonis() = 0;

        //these two methods follow the template method because it is is used to 
        //define the skeleton of an algorithm in the Soldiers base class while 
        //allowing derived classes to override specific steps of the algorithm 
        //without changing its structure.

        virtual void engage();      
        virtual void disengage();

        //from memento

        Memento* militusMemento();
        void vivificaMemento(Memento* mem);

        virtual ~Soldiers();

        void setAttributes(int h, int dam, int def, int amt, string n);

        int getHealth();
        int getDamage();
        int getDefence();
        int getAmountOfSoldiers();
        string getName();
};

#endif;