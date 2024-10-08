#ifndef INFANTRY_H
#define INFANTRY_H

#include "Soldiers.h"

using namespace std;

class Soldiers;

class Infantry : public Soldiers {
    
    private: 
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        string unitName;

        // Private Methods
        void prepare();
        void execute();
        void retreat();
        void rest();

    public:
        // Added edited (default) constructor for 4.1. Factory Method to set default values when creating units and soldiers
        Infantry();
        ~Infantry();

        // Added helper functions for 4.1. Factory Method
        // Used in the factory .cpp files to access attributes since the pointer is private
        int getHealthPerSoldier() const;
        int getDamagePerSoldier() const;
        int getDefencePerSoldier() const;
        int getAmountOfSoldiersPerUnit() const;
        string getUnitName() const;

        // Added helper functions for the testing main (accessing of variables outside the classes)
        void setHealthPerSoldier(int health);
        void setDamagePerSoldier(int damage);
        void setDefencePerSoldier(int defence);
        void setAmountOfSoldiersPerUnit(int amount);
        void setUnitName(const std::string &name);

        // Function for 4.2. Prototype (clone - making a copy of itself)
        Soldiers* clonis();

        void engage();
        void disengage();

        void setAttributes(int h, int dam, int def, int amt, string n);
};

#endif // INFANTRY_H