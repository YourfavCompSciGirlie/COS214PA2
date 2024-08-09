#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include "SoldierFactory.h"
#include "InfantryFactory.h"
#include "ShieldBearerFactory.h"
#include "BoatmanFactory.h"
#include "Soldiers.h"
#include "Infantry.h"
#include "ShieldBearer.h"
#include "Boatman.h"
#include "Memento.h"
#include "Caretaker.h"

using namespace std;

void testFactoryMethod();
void testPrototypePattern();
void testTemplateMethod();
void testMementoPattern();
void testCalculateFunctions();


int main() {

    // This will be our testing main :)
    cout << "------------------------- Testing Main Starts ----------------------------\n\n\n";

    // Calling the external testing classes:
    cout << "------------------------- Testing Factory Method 1 -----------------------\n\n";
    testCalculateFunctions();
    cout << endl;

    cout << "------------------------- Testing Factory Method 2 -----------------------\n\n";
    testFactoryMethod();
    cout << endl;

    cout << "------------------------- Testing Prototype ------------------------------\n\n";
    testPrototypePattern();
    cout << endl;

    cout << "------------------------- Testing Template Method -------------------------\n\n";
    testTemplateMethod();
    cout << endl;

    cout << "------------------------- Testing Memento ---------------------------------\n\n";
    testMementoPattern();
    cout << endl;
    
    return 0;
}


void testCalculateFunctions() {
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    cout << endl;

    cout << "- Testing Calculate Functions from Factory Method:\n\n";

    // Test calculateTotalHealthPerUnit
    cout << "Infantry Total Health: " << infantryFactory.calculateTotalHealthPerUnit() << "\n\n";
    cout << "ShieldBearer Total Health: " << shieldBearerFactory.calculateTotalHealthPerUnit() << "\n\n";
    cout << "Boatman Total Health: " << boatmanFactory.calculateTotalHealthPerUnit() << '\n';

    cout << endl;

    // Test calculateTotalDamagePerUnit
    cout << "Infantry Total Damage: " << infantryFactory.calculateTotalDamagePerUnit() << "\n\n";
    cout << "ShieldBearer Total Damage: " << shieldBearerFactory.calculateTotalDamagePerUnit() << "\n\n";
    cout << "Boatman Total Damage: " << boatmanFactory.calculateTotalDamagePerUnit() << '\n';

    cout << endl;

    // Test calculateTotalDefencePerUnit
    cout << "Infantry Total Defence: " << infantryFactory.calculateTotalDefencePerUnit() << "\n\n";
    cout << "ShieldBearer Total Defence: " << shieldBearerFactory.calculateTotalDefencePerUnit() << "\n\n";
    cout << "Boatman Total Defence: " << boatmanFactory.calculateTotalDefencePerUnit() << '\n';
    
    cout << endl;
}



void testFactoryMethod() {
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    cout << endl;

    Soldiers* infantry = infantryFactory.createUnit();
    Soldiers* shieldBearer = shieldBearerFactory.createUnit();
    Soldiers* boatman = boatmanFactory.createUnit();

    cout << endl;

    std::cout << "- Factory Method Test:\n";
    std::cout << "Infantry - Health: " << infantry->getHealthPerSoldier() 
              << ", Damage: " << infantry->getDamagePerSoldier() 
              << ", Defence: " << infantry->getDefencePerSoldier() << '\n';

    std::cout << "ShieldBearer - Health: " << shieldBearer->getHealthPerSoldier() 
              << ", Damage: " << shieldBearer->getDamagePerSoldier() 
              << ", Defence: " << shieldBearer->getDefencePerSoldier() << '\n';

    std::cout << "Boatman - Health: " << boatman->getHealthPerSoldier() 
              << ", Damage: " << boatman->getDamagePerSoldier() 
              << ", Defence: " << boatman->getDefencePerSoldier() << '\n';

    cout << endl;          

    delete infantry;
    delete shieldBearer;
    delete boatman;

    cout << endl;
}



void testPrototypePattern() {
    Infantry infantry;

    cout << endl;

    infantry.setHealthPerSoldier(110);
    infantry.setDamagePerSoldier(75);
    infantry.setDefencePerSoldier(44);
    infantry.setAmountOfSoldiersPerUnit(5);
    infantry.setUnitName("Infantry Unit 12");

    Soldiers* clonedInfantry = infantry.clonis();

    std::cout << "- Prototype Pattern Test:\n";
    std::cout << "Cloned Infantry - Health: " << clonedInfantry->getHealthPerSoldier() 
              << ", Damage: " << clonedInfantry->getDamagePerSoldier() 
              << ", Defence: " << clonedInfantry->getDefencePerSoldier()
              << ", Number of Soldiers: " << clonedInfantry->getAmountOfSoldiersPerUnit()
              << ", ID: " << clonedInfantry->getUnitName() << '\n';

    cout << endl;

    delete clonedInfantry;
}



void testTemplateMethod() {
    Infantry infantry;
    ShieldBearer shieldBearer;
    Boatman boatman;

    cout << endl;

    std::cout << "- Template Method Test:\n\n";
    std::cout << "Infantry:\n\n";
    infantry.engage();
    infantry.disengage();

    std::cout << "\nShieldBearer:\n\n";
    shieldBearer.engage();
    shieldBearer.disengage();

    std::cout << "\nBoatman:\n\n";
    boatman.engage();
    boatman.disengage();

    cout << endl;
}



void testMementoPattern() {
    Infantry infantry;

    cout << endl; 

    infantry.setHealthPerSoldier(152);
    infantry.setDamagePerSoldier(67);
    infantry.setDefencePerSoldier(30);
    infantry.setAmountOfSoldiersPerUnit(15);
    infantry.setUnitName("Infantry Unit 23");

    Caretaker caretaker;

    caretaker.addMemento(infantry.militusMemento());

    infantry.setHealthPerSoldier(90);
    infantry.setDamagePerSoldier(40);
    infantry.setDefencePerSoldier(20);

    std::cout << "- Memento Pattern Test:\n";
    std::cout << "Current Infantry - Health: " << infantry.getHealthPerSoldier() 
              << ", Damage: " << infantry.getDamagePerSoldier() 
              << ", Defence: " << infantry.getDefencePerSoldier() << '\n';

    infantry.vivificaMemento(caretaker.restoreState());

    std::cout << "Restored Infantry - Health: " << infantry.getHealthPerSoldier() 
              << ", Damage: " << infantry.getDamagePerSoldier() 
              << ", Defence: " << infantry.getDefencePerSoldier() << '\n';

    cout << endl;
}



