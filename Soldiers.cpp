#include "Soldiers.h"

void Soldiers::engage()
{
    prepare();
    execute();
}

void Soldiers::disengage()
{
    retreat();
    rest();
}

void Soldiers::setAttributes(int h, int dam, int def, int amt, string n)
{
    this->healthPerSoldier = h;
    this->damagePerSoldier = dam;
    this->defencePerSoldier = def;
    this->amountOfSoldiersPerUnit = amt;
    this->unitName = n;
}

Memento* Soldiers::militusMemento()
{
    return new Memento(healthPerSoldier, damagePerSoldier, defencePerSoldier, amountOfSoldiersPerUnit, unitName);
}
void Soldiers::vivificaMemento(Memento* mem)
{
    if(mem)
    {
        healthPerSoldier = mem->getHealthPerSoldier();
        damagePerSoldier = mem->getDamagePerSoldier();
        defencePerSoldier = mem->getDefencePerSoldier();
        amountOfSoldiersPerUnit = mem->getAmountOfSoldiersPerUnit();
        unitName = mem->getUnitName();
    }
}

// Added helper functions for 4.1. Factory Method
// Used in the factory .cpp files to access attributes since the pointer is private
int Soldiers::getHealthPerSoldier() const {
    return healthPerSoldier;
}

int Soldiers::getDamagePerSoldier() const {
    return damagePerSoldier;
}

int Soldiers::getDefencePerSoldier() const {
    return defencePerSoldier;
}

int Soldiers::getAmountOfSoldiersPerUnit() const {
    return amountOfSoldiersPerUnit;
}

string Soldiers::getUnitName() const {
    return unitName;
}

// Added helper functions for the testing main (accessing of variables outside the classes)
void Soldiers::setHealthPerSoldier(int health) {
    healthPerSoldier = health; 
}

void Soldiers::setDamagePerSoldier(int damage) { 
    damagePerSoldier = damage; 
}

void Soldiers::setDefencePerSoldier(int defence) { 
    defencePerSoldier = defence;
}

void Soldiers::setAmountOfSoldiersPerUnit(int amount) { 
    amountOfSoldiersPerUnit = amount;
}

void Soldiers::setUnitName(const std::string &name) { 
    unitName = name; 
}

Soldiers::Soldiers() {
    cout << "Soldier making is in procession.. " << endl;
}

Soldiers::~Soldiers() 
{
    cout<< "Soldiers has been destroyed."<< endl; 
}