#include "Infantry.h"

using namespace std;


// Added edited (default) constructor for 4.1. Factory Method to set default values when creating units and soldiers
Infantry::Infantry() {
        healthPerSoldier = 100;
        damagePerSoldier = 50;
        defencePerSoldier = 30;
        amountOfSoldiersPerUnit = 10;
        unitName = "Infantry Unit";
        std::cout << "Infantry Soldier has been created with default values.\n";
        std::cout << "Health: " << healthPerSoldier << ", Damage: " << damagePerSoldier << ", Defence: " << defencePerSoldier << ", Number of soldiers: " << amountOfSoldiersPerUnit << '\n';
}



Infantry::~Infantry() {
    cout << "Infantry has been destroyed." << endl; 
}



// Added helper functions for 4.1. Factory Method
// Used in the factory .cpp files to access attributes since the pointer is private
int Infantry::getHealthPerSoldier() const {
        return healthPerSoldier;
}



int Infantry::getDamagePerSoldier() const {
        return damagePerSoldier;
}



int Infantry::getDefencePerSoldier() const {
    return defencePerSoldier;
}



int Infantry::getAmountOfSoldiersPerUnit() const {
    return amountOfSoldiersPerUnit;
}



string Infantry::getUnitName() const {
    return unitName;
}



// Added helper functions for the testing main (accessing of variables outside the classes)
void Infantry::setHealthPerSoldier(int health) {
    healthPerSoldier = health; 
}



void Infantry::setDamagePerSoldier(int damage) { 
    damagePerSoldier = damage; 
}



void Infantry::setDefencePerSoldier(int defence) { 
    defencePerSoldier = defence;
}



void Infantry::setAmountOfSoldiersPerUnit(int amount) { 
    amountOfSoldiersPerUnit = amount;
}



void Infantry::setUnitName(const std::string &name) { 
    unitName = name; 
}



// Function for 4.2. Prototype (clone - making a copy of itself)
Soldiers* Infantry::clonis() {
    // DEEP COPY
    return new Infantry(*this);
}



// Functions for 4.3. Template Method
void Infantry::prepare() {
    cout<< unitName << " prepares for battle! " << endl;
    int boosters = (healthPerSoldier + defencePerSoldier) / 10;
    cout << "Booster: +" << boosters << " points to the Infantry." << endl;
}



void Infantry::execute() {
    cout << unitName << " charges towards the enemy!!" << endl;
    cout << "The infantry charge at the enemy with spears raised high. They violently and brutally stabbing at the enemy..." << endl;
    
    int battleCounter = (damagePerSoldier > defencePerSoldier) ? 0:2;
    
    if (battleCounter == 0) {
        cout << unitName << " wins the battle! Enemies are retreating..." << endl;
    } else if (battleCounter == 1) {
        cout << "It's not looking good for any one of the sides..." << endl;
    } else {
        cout << unitName << " is losing this one badly." << endl;
    }
}



void Infantry::retreat() {
    cout << unitName << " retreats to safer grounds." << endl;

    int safety = (defencePerSoldier > damagePerSoldier) ? 0:1;
    
    if (safety == 0) {
        cout << unitName << " has successfully retreated away from the enemy forces." << endl;
    } else {
        cout << "Enemy troops pursue faster..." << endl;
    }
}



void Infantry::rest() {
    int recovBoost = (healthPerSoldier + amountOfSoldiersPerUnit) / 10;
    cout << unitName << " is resting, +" << recovBoost << " health points to the infantry." << endl; 

}



void Infantry::engage() {
    prepare();
    execute();
}



void Infantry::disengage() {
    retreat();
    rest();
}