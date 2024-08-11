#include "Boatman.h"

using namespace std;


// Added edited (default) constructor for 4.1. Factory Method to set default values when creating units and soldiers
Boatman::Boatman() {
        healthPerSoldier = 80;
        damagePerSoldier = 70;
        defencePerSoldier = 20;
        amountOfSoldiersPerUnit = 15;
        unitName = "Boatman Unit";
        std::cout << "Boatman Soldier has been created with default values.\n";
        std::cout << "Health: " << healthPerSoldier << ", Damage: " << damagePerSoldier << ", Defence: " << defencePerSoldier << ", Number of soldiers: " << amountOfSoldiersPerUnit << '\n';
}



Boatman::~Boatman() {
    cout<< "Boatman has been destroyed." << endl; 
}



// Added helper functions for 4.1. Factory Method
// Used in the factory .cpp files to access attributes since the pointer is private
int Boatman::getHealthPerSoldier() const {
    return healthPerSoldier;
}



int Boatman::getDamagePerSoldier() const {
    return damagePerSoldier;
}



int Boatman::getDefencePerSoldier() const {
    return defencePerSoldier;
}



int Boatman::getAmountOfSoldiersPerUnit() const {
    return amountOfSoldiersPerUnit;
}



string Boatman::getUnitName() const {
    return unitName;
}



// Added helper functions for the testing main (accessing of variables outside the classes)
void Boatman::setHealthPerSoldier(int health) {
    healthPerSoldier = health; 
}



void Boatman::setDamagePerSoldier(int damage) { 
    damagePerSoldier = damage; 
}



void Boatman::setDefencePerSoldier(int defence) { 
    defencePerSoldier = defence;
}



void Boatman::setAmountOfSoldiersPerUnit(int amount) { 
    amountOfSoldiersPerUnit = amount;
}



void Boatman::setUnitName(const std::string &name) { 
    unitName = name; 
}



// Function for 4.2. Prototype (clone - making a copy of itself)
Soldiers* Boatman::clonis() {
    // DEEP COPY
    return new Boatman(*this);
}



// Functions for 4.3. Template Method
void Boatman::prepare() {
    cout << unitName << " prepares for battle!" << endl;
    cout << "Boatmen position their boats..." << endl;

    int boost = (healthPerSoldier + defencePerSoldier) / 10;
    cout << "+" << boost << " points to the units." << endl; 
}



void Boatman::execute() {
    cout << unitName << " emerge from the river. The war begins as boatmen launch their attacks..." << endl;

    int battle = (damagePerSoldier>defencePerSoldier) ? 0:2;

    if (battle == 0) {
        cout << unitName << " have declared victory over the enemy troops!"<< endl;
    } else if (battle == 1) {
        cout << "It's not looking good for " << unitName << ".";
    } else {
        cout << unitName << " is losing hard to the enemy troops." << endl;
    }
}



void Boatman::retreat() {
    cout << unitName << " retreats to safety..."<< endl;

    int safety = (defencePerSoldier > damagePerSoldier)? 0:1;
    
    if (safety == 0) {
        cout << unitName << " has retreated safely far away from enemy troops."<< endl;
    } else {
        cout << "They cannot escape. Shame." << endl;
    }
}



void Boatman::rest() {
    int recovery = (healthPerSoldier + amountOfSoldiersPerUnit) / 10;
    cout << unitName << " recovers safely away from enemy troops, +" << recovery << " health points."<< endl;
}



void Boatman::engage() {
    prepare();
    execute();
}



void Boatman::disengage() {
    retreat();
    rest();
}



void Boatman::setAttributes(int h, int dam, int def, int amt, string n) {
    healthPerSoldier = h;
    damagePerSoldier = dam;
    defencePerSoldier = def;
    amountOfSoldiersPerUnit = amt;
    unitName = n;
}