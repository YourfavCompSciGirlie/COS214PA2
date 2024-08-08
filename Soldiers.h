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

        // Added helper functions for 4.1. Factory Method
        // Used in the factory .cpp files to access attributes since the pointer is private
        int getHealthPerSoldier() const;
        int getDamagePerSoldier() const;
        int getDefencePerSoldier() const;
        int getAmountOfSoldiersPerUnit() const;

        // Added helper functions for the testing main (accessing of variables outside the classes)
        void setHealthPerSoldier(int health);
        void setDamagePerSoldier(int damage);
        void setDefencePerSoldier(int defence);
        void setAmountOfSoldiersPerUnit(int amount);
        void setUnitName(const std::string &name);

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

        virtual ~Soldiers();

        void setAttributes(int h, int dam, int def, int amt, string n);

        int getHealth();
        int getDamage();
        int getDefence();
        int getAmountOfSoldiers();
        string getName();
};

#endif;