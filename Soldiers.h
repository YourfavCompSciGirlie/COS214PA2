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
        int amountOfSoldiersPerUnit;
        string unitName;

        // methods

        virtual void prepare() = 0;
        virtual void execute() = 0;
        virtual void retreat() = 0;
        virtual void rest() = 0;
        

    public:

        // Added helper functions for 4.1. Factory Method
        // Used in the factory .cpp files to access attributes since the pointer is private
        virtual int getHealthPerSoldier() const = 0;
        virtual int getDamagePerSoldier() const = 0;
        virtual int getDefencePerSoldier() const = 0;
        virtual int getAmountOfSoldiersPerUnit() const = 0;
        virtual string getUnitName() const = 0;

        // Added helper functions for the testing main (accessing of variables outside the classes)
        virtual void setHealthPerSoldier(int health) = 0;
        virtual void setDamagePerSoldier(int damage) = 0;
        virtual void setDefencePerSoldier(int defence) = 0;
        virtual void setAmountOfSoldiersPerUnit(int amount) = 0;
        virtual void setUnitName(const std::string &name) = 0;

        // Function for 4.2. Prototype (clone - making a copy of itself)
        // Pure virtual because of Abstract class
        // Will be implemented virtual in derived classes: Infantry, ShieldBearer, Boatman
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

        Soldiers();
        virtual ~Soldiers();

        void setAttributes(int h, int dam, int def, int amt, string n);
};

#endif