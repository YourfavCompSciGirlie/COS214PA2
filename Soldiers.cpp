#include "Soldiers.h"


Soldiers::Soldiers() {
    cout << "Soldier making is in procession..." << endl;
}



Soldiers::~Soldiers() {
    cout<< "Soldiers has been destroyed."<< endl; 
}



Memento* Soldiers::militusMemento() {
    return new Memento(healthPerSoldier, damagePerSoldier, defencePerSoldier, amountOfSoldiersPerUnit, unitName);
}



void Soldiers::vivificaMemento(Memento* mem) {
    if(mem) {
        healthPerSoldier = mem->healthPerSoldier;
        damagePerSoldier = mem->damagePerSoldier;
        defencePerSoldier = mem->defencePerSoldier;
        amountOfSoldiersPerUnit = mem->amountOfSoldiersPerUnit;
        unitName = mem->unitName;
    }
}



// void Soldiers::setAttributes(int h, int dam, int def, int amt, string n)
// {
//     this->healthPerSoldier = h;
//     this->damagePerSoldier = dam;
//     this->defencePerSoldier = def;
//     this->amountOfSoldiersPerUnit = amt;
//     this->unitName = n;
// }



void Soldiers::engage() {
    prepare();
    execute();
}



void Soldiers::disengage() {
    retreat();
    rest();
}

