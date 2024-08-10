#include "ShieldBearer.h"

using namespace std;


// Added edited (default) constructor for 4.1. Factory Method to set default values when creating units and soldiers
ShieldBearer::ShieldBearer() {
        healthPerSoldier = 120;
        damagePerSoldier = 40;
        defencePerSoldier = 50;
        amountOfSoldiersPerUnit = 8;
        unitName = "ShieldBearer Unit";
        std::cout << "ShieldBearer Soldier has been created with default values.\n";
        std::cout << "Health: " << healthPerSoldier << ", Damage: " << damagePerSoldier << ", Defence: " << defencePerSoldier << ", Number of soldiers: " << amountOfSoldiersPerUnit << '\n';
}



ShieldBearer::~ShieldBearer() {
    cout<< "ShieldBearer has been destroyed."<< endl; 
}



// Added helper functions for 4.1. Factory Method
// Used in the factory .cpp files to access attributes since the pointer is private
int ShieldBearer::getHealthPerSoldier() const {
        return healthPerSoldier;
}



int ShieldBearer::getDamagePerSoldier() const {
        return damagePerSoldier;
}



int ShieldBearer::getDefencePerSoldier() const {
        return defencePerSoldier;
}



int ShieldBearer::getAmountOfSoldiersPerUnit() const {
        return amountOfSoldiersPerUnit;
}   



string ShieldBearer::getUnitName() const {   
        return unitName;
}


// Added helper functions for the testing main (accessing of variables outside the classes)
void ShieldBearer::setHealthPerSoldier(int health) {
    healthPerSoldier = health; 
}



void ShieldBearer::setDamagePerSoldier(int damage) { 
    damagePerSoldier = damage; 
}



void ShieldBearer::setDefencePerSoldier(int defence) { 
    defencePerSoldier = defence;
}



void ShieldBearer::setAmountOfSoldiersPerUnit(int amount) { 
    amountOfSoldiersPerUnit = amount;
}



void ShieldBearer::setUnitName(const std::string &name) { 
    unitName = name; 
}



// Function for 4.2. Prototype (clone - making a copy of itself)
// Implementation made virtual (different from the UML)
Soldiers* ShieldBearer::clonis() {
    // DEEP COPY
    return new ShieldBearer(*this);
}



// Functions for 4.3. Template Method
void ShieldBearer::prepare() {
    cout << unitName << " prepares for battle by forming a strong defence line..."<< endl;
    int defence = (healthPerSoldier + defencePerSoldier) / 10;
    cout << "Defence boost: +" << defence << " points to the Shield Bearers." << endl;
}



void ShieldBearer::execute() {
    cout << unitName << " push forward with their shields raised high towards the enemy forces!!" << endl;
    
    int battle = (defencePerSoldier > damagePerSoldier) ? 0:1;
    
    if (battle == 0) {
        cout << unitName << " gains victory over the enemy troops!!!" << endl;
    } else if (battle == 1) {
        cout << unitName << " is under intense pressure from the enemy forces!!!" << endl;
    }
}



void ShieldBearer::retreat() {
    cout << unitName << " retreats to safety swiftly..." << endl;

    int safety = (defencePerSoldier>damagePerSoldier)? 0:1;
    
    if (safety == 0) {
        cout << unitName << " has retreated safely far away from the enemy troops." << endl;
    } else {
        cout << "They cannot escape, enemy troops pursue further!!!" << endl;
    }
}



void ShieldBearer::rest() {
    int recovery = (healthPerSoldier + amountOfSoldiersPerUnit) / 10;
    cout << unitName << " recovers safely away from enemy troops, +" << recovery << " health points gained." << endl;
}



void ShieldBearer::engage() {
    prepare();
    execute();
}



void ShieldBearer::disengage() {
    retreat();
    rest();
}
