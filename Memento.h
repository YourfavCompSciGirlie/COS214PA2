#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>
using namespace std;

class Memento{

    private: 
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        string unitName;

        Memento(int value1, int value2, int value3, int value4, string value5);
        friend class Soldiers;

    public:

        //subject to change based on progression if implementation
        int getHealthPerSoldier() const;
        int getDamagePerSoldier() const;
        int getDefencePerSoldier() const;
        int getAmountOfSoldiersPerUnit() const;
        string getUnitName() const;

};
#endif