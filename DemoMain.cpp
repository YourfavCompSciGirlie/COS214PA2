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

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

int main() {

    cout << "------------------------- " << CYAN << "Testing Main Starts" << RESET << " ----------------------------" << endl << endl;

    cout << "------------------------- " << YELLOW << "Testing Calculate Functions" << RESET << " -----------------------" << endl;
    testCalculateFunctions();
    cout << endl;

    cout << "------------------------- " << GREEN << "Testing Factory Method" << RESET << " -----------------------" << endl;
    testFactoryMethod();
    cout << endl;

    cout << "------------------------- " << BLUE << "Testing Prototype" << RESET << " ------------------------------" << endl;
    testPrototypePattern();
    cout << endl;

    cout << "------------------------- " << RED << "Testing Template Method" << RESET << " -------------------------" << endl;
    testTemplateMethod();
    cout << endl;

    cout << "------------------------- " << CYAN << "Testing Memento" << RESET << " ---------------------------------" << endl << endl;
    testMementoPattern();
    cout << endl;
    
    return 0;
}


void testCalculateFunctions() {
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    cout << "Testing Calculate Functions:\n";

    cout << BLUE << "Infantry Total Health: " << infantryFactory.calculateTotalHealthPerUnit() << RESET << '\n';
    cout << GREEN << "ShieldBearer Total Health: " << shieldBearerFactory.calculateTotalHealthPerUnit() << RESET << '\n';
    cout << RED << "Boatman Total Health: " << boatmanFactory.calculateTotalHealthPerUnit() << RESET << '\n';

    cout << BLUE << "Infantry Total Damage: " << infantryFactory.calculateTotalDamagePerUnit() << RESET << '\n';
    cout << GREEN << "ShieldBearer Total Damage: " << shieldBearerFactory.calculateTotalDamagePerUnit() << RESET << '\n';
    cout << RED << "Boatman Total Damage: " << boatmanFactory.calculateTotalDamagePerUnit() << RESET << '\n';

    cout << BLUE << "Infantry Total Defence: " << infantryFactory.calculateTotalDefencePerUnit() << RESET << '\n';
    cout << GREEN << "ShieldBearer Total Defence: " << shieldBearerFactory.calculateTotalDefencePerUnit() << RESET << '\n';
    cout << RED << "Boatman Total Defence: " << boatmanFactory.calculateTotalDefencePerUnit() << RESET << '\n';
    cout << endl;
}


void testFactoryMethod() {
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    Soldiers* infantry = infantryFactory.createUnit();
    Soldiers* shieldBearer = shieldBearerFactory.createUnit();
    Soldiers* boatman = boatmanFactory.createUnit();

    cout << "Factory Method Test:\n";
    cout << BLUE << "Infantry - Health: " << infantry->getHealthPerSoldier() 
              << ", Damage: " << infantry->getDamagePerSoldier() 
              << ", Defence: " << infantry->getDefencePerSoldier() << RESET << '\n';

    cout << GREEN << "ShieldBearer - Health: " << shieldBearer->getHealthPerSoldier() 
              << ", Damage: " << shieldBearer->getDamagePerSoldier() 
              << ", Defence: " << shieldBearer->getDefencePerSoldier() << RESET << '\n';

    cout << RED << "Boatman - Health: " << boatman->getHealthPerSoldier() 
              << ", Damage: " << boatman->getDamagePerSoldier() 
              << ", Defence: " << boatman->getDefencePerSoldier() << RESET << '\n';

    delete infantry;
    delete shieldBearer;
    delete boatman;
    cout << endl;
}


void testPrototypePattern() {
    Infantry infantry;
    infantry.setHealthPerSoldier(100);
    infantry.setDamagePerSoldier(50);
    infantry.setDefencePerSoldier(30);
    infantry.setAmountOfSoldiersPerUnit(10);
    infantry.setUnitName("Infantry Unit");

    Soldiers* clonedInfantry = infantry.clonis();

    cout << "Prototype Pattern Test:\n";
    cout << BLUE << "Cloned Infantry - Health: " << clonedInfantry->getHealthPerSoldier() 
              << ", Damage: " << clonedInfantry->getDamagePerSoldier() 
              << ", Defence: " << clonedInfantry->getDefencePerSoldier() << RESET << '\n';

    delete clonedInfantry;
    cout << endl;
}


void testTemplateMethod() {
    Infantry infantry;
    ShieldBearer shieldBearer;
    Boatman boatman;

    cout << CYAN << "Template Method Test:\n" << RESET << endl;

    cout << BLUE << "Infantry:\n" << RESET;
    infantry.engage();
    infantry.disengage();
    cout << endl;

    cout << GREEN << "ShieldBearer:\n" << RESET;
    shieldBearer.engage();
    shieldBearer.disengage();
    cout << endl;

    cout << RED << "Boatman:\n" << RESET;
    boatman.engage();
    boatman.disengage();
    cout << endl;
}


void testMementoPattern() {
    Infantry infantry;
    infantry.setHealthPerSoldier(100);
    infantry.setDamagePerSoldier(50);
    infantry.setDefencePerSoldier(30);
    infantry.setAmountOfSoldiersPerUnit(10);
    infantry.setUnitName("Infantry Unit");

    Caretaker caretaker;

    caretaker.addMemento(infantry.militusMemento());

    infantry.setHealthPerSoldier(90);
    infantry.setDamagePerSoldier(40);
    infantry.setDefencePerSoldier(20);

    cout << "Memento Pattern Test:\n";
    cout << BLUE << "Current Infantry - Health: " << infantry.getHealthPerSoldier() 
              << ", Damage: " << infantry.getDamagePerSoldier() 
              << ", Defence: " << infantry.getDefencePerSoldier() << RESET << '\n';

    infantry.vivificaMemento(caretaker.restoreState());

    cout << GREEN << "Restored Infantry - Health: " << infantry.getHealthPerSoldier() 
              << ", Damage: " << infantry.getDamagePerSoldier() 
              << ", Defence: " << infantry.getDefencePerSoldier() << RESET << '\n';

    cout << endl;
}
