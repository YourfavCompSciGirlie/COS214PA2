#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include "SoldierFactory.h"
#include "Infantry.h"
#include "ShieldBearerFactory.h"
#include "BoatmanFactory.h"
#include "Soldiers.h"
#include "Infantry.h"
#include "ShieldBearer.h"
#include "Boatman.h"
#include "Memento.h"
#include "Caretaker.h"

using namespace std;


int main() {

    // This will be our testing main :)
    cout << "------------------------- Testing Main Starts -------------------------" << endl;

    cout << "------------------------- Testing Factory Method -------------------------" << endl;

    // Calling the external testing classes:
    testFactoryMethod();

    cout << "------------------------- Testing Prototype -------------------------" << endl;

    // testPrototypePattern();

    // cout << "------------------------- Testing Template Method -------------------------" << endl;

    // testTemplateMethod();

    // cout << "------------------------- Testing Memento -------------------------" << endl;

    // testMementoPattern();
    
    return 0;
}


void testFactoryMethod() {
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    Soldiers* infantry = infantryFactory.createUnit();
    Soldiers* shieldBearer = shieldBearerFactory.createUnit();
    Soldiers* boatman = boatmanFactory.createUnit();

    std::cout << "Factory Method Test:\n";
    std::cout << "Infantry - Health: " << infantry->getHealthPerSoldier() 
              << ", Damage: " << infantry->getDamagePerSoldier() 
              << ", Defence: " << infantry->getDefencePerSoldier() << '\n';

    std::cout << "ShieldBearer - Health: " << shieldBearer->getHealthPerSoldier() 
              << ", Damage: " << shieldBearer->getDamagePerSoldier() 
              << ", Defence: " << shieldBearer->getDefencePerSoldier() << '\n';

    std::cout << "Boatman - Health: " << boatman->getHealthPerSoldier() 
              << ", Damage: " << boatman->getDamagePerSoldier() 
              << ", Defence: " << boatman->getDefencePerSoldier() << '\n';

    delete infantry;
    delete shieldBearer;
    delete boatman;
}

// void testPrototypePattern() {
//     Infantry infantry;
//     infantry.setHealthPerSoldier(100);
//     infantry.setDamagePerSoldier(50);
//     infantry.setDefencePerSoldier(30);
//     infantry.setAmountOfSoldiersPerUnit(10);
//     infantry.setUnitName("Infantry Unit");

//     Soldiers* clonedInfantry = infantry.clonis();

//     std::cout << "Prototype Pattern Test:\n";
//     std::cout << "Cloned Infantry - Health: " << clonedInfantry->getHealthPerSoldier() 
//               << ", Damage: " << clonedInfantry->getDamagePerSoldier() 
//               << ", Defence: " << clonedInfantry->getDefencePerSoldier() << '\n';

//     delete clonedInfantry;
// }

// void testTemplateMethod() {
//     Infantry infantry;
//     ShieldBearer shieldBearer;
//     Boatman boatman;

//     std::cout << "Template Method Test:\n";
//     std::cout << "Infantry:\n";
//     infantry.engage();
//     infantry.disengage();

//     std::cout << "\nShieldBearer:\n";
//     shieldBearer.engage();
//     shieldBearer.disengage();

//     std::cout << "\nBoatman:\n";
//     boatman.engage();
//     boatman.disengage();
// }

// void testMementoPattern() {
//     Infantry infantry;
//     infantry.setHealthPerSoldier(100);
//     infantry.setDamagePerSoldier(50);
//     infantry.setDefencePerSoldier(30);
//     infantry.setAmountOfSoldiersPerUnit(10);
//     infantry.setUnitName("Infantry Unit");

//     CareTaker careTaker;

//     careTaker.saveState(infantry.militusMemento());

//     infantry.setHealthPerSoldier(90);
//     infantry.setDamagePerSoldier(40);
//     infantry.setDefencePerSoldier(20);

//     std::cout << "Memento Pattern Test:\n";
//     std::cout << "Current Infantry - Health: " << infantry.getHealthPerSoldier() 
//               << ", Damage: " << infantry.getDamagePerSoldier() 
//               << ", Defence: " << infantry.getDefencePerSoldier() << '\n';

//     infantry.vivificaMemento(careTaker.restoreState());

//     std::cout << "Restored Infantry - Health: " << infantry.getHealthPerSoldier() 
//               << ", Damage: " << infantry.getDamagePerSoldier() 
//               << ", Defence: " << infantry.getDefencePerSoldier() << '\n';
// }



