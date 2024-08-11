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

// Function Prototypes
void thankyou();
void testCalculateFunctions();
void testFactoryMethod();
void testPrototypePattern();
void testTemplateMethod();
void testMementoPattern();
void printDivider(const string& title, const string& color);

// ANSI color codes
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BG_BLACK = "\033[40m";
const string BG_RED = "\033[41m";
const string BG_GREEN = "\033[42m";
const string BG_YELLOW = "\033[43m";
const string BG_BLUE = "\033[44m";
const string BG_MAGENTA = "\033[45m";
const string BG_CYAN = "\033[46m";
const string BG_WHITE = "\033[47m";

int main() {

    cout << RED << BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                       Testing Main Starts                             ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n" << RESET << "\n";

    // Factory Method 1
    printDivider("Testing Factory Method 1", GREEN);
    testCalculateFunctions();
    cout << endl;

    for(int i=0; i<100; i++)
    {
        cout<< GREEN << "\u25A0" << " " << RESET;
    }
    cout << endl << endl << endl;

    // Factory Method 2
    printDivider("Testing Factory Method 2", YELLOW);
    testFactoryMethod();
    cout << endl;

    for(int i=0; i<100; i++)
    {
        cout<< YELLOW << "\u25CF" << " " << RESET;
    }
    cout << endl << endl << endl;

    // Prototype Pattern
    printDivider("Testing Prototype Pattern", CYAN);
    testPrototypePattern();
    cout << endl;

    for(int i=0; i<100; i++)
    {
        cout<< CYAN << "\u25B2" << " " << RESET;
    }
    cout << endl << endl << endl;

    // Template Method
    printDivider("Testing Template Method", BLUE);
    testTemplateMethod();
    cout << endl;

    for(int i=0; i<100; i++)
    {
        cout<< BLUE << "\u2665" << " " << RESET;
    }
    cout << endl << endl << endl;

    // Memento Pattern
    printDivider("Testing Memento Pattern", MAGENTA);
    testMementoPattern();
    cout << endl;

    for(int i=0; i<70; i++)
    {
        cout<< MAGENTA << "<>" << " " << RESET;
    }
    cout << endl << endl << endl;

    // cout << BG_BLUE << BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    // cout << "║                       Testing Main Ends                               ║\n";
    // cout << "╚═══════════════════════════════════════════════════════════════════════╝" << RESET << "..................\n"
    //     << "------------------------------------------------------------------------------------------------------------------------------------------------" 
    //     << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << RED<< BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                       Testing Main Ends                               ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n" << RESET << "\n";
    
    thankyou();

    return 0;
}

// Function to print a colored divider with a title
void printDivider(const string& title, const string& color) {
    cout << color << BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║ " << title << string(65 - title.length(), ' ') << "     ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n" << RESET << "\n";
}

void thankyou()
{
    cout << endl << endl;
    cout << MAGENTA << "-------------------------------- Thank you --------------------------------" << RESET << endl << endl << endl;
}

void testCalculateFunctions() {
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    cout << endl;

    cout << GREEN << "- Testing Calculate Functions from Factory Method:\n\n" << RESET;

    // Calculate Total Health per Unit
    cout << YELLOW << " • Infantry Total Health: " << infantryFactory.calculateTotalHealthPerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Health: " << shieldBearerFactory.calculateTotalHealthPerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Health: " << boatmanFactory.calculateTotalHealthPerUnit() << '\n' << RESET;

    cout << endl;

    // Calculate Total Damage per Unit
    cout << YELLOW << " • Infantry Total Damage: " << infantryFactory.calculateTotalDamagePerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Damage: " << shieldBearerFactory.calculateTotalDamagePerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Damage: " << boatmanFactory.calculateTotalDamagePerUnit() << '\n' << RESET;

    cout << endl;

    // Calculate Total Defence per Unit
    cout << YELLOW << " • Infantry Total Defence: " << infantryFactory.calculateTotalDefencePerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Defence: " << shieldBearerFactory.calculateTotalDefencePerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Defence: " << boatmanFactory.calculateTotalDefencePerUnit() << '\n' << RESET;

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

    cout << YELLOW << "- Factory Method Test:\n\n" << RESET;

    cout << GREEN << " • Infantry: \n";
    cout << "   - Health : " << infantry->getHealthPerSoldier() << "\n";
    cout << "   - Damage : " << infantry->getDamagePerSoldier() << "\n";
    cout << "   - Defence: " << infantry->getDefencePerSoldier() << "\n\n" << RESET;

    cout << BLUE << " • ShieldBearer: \n";
    cout << "   - Health : " << shieldBearer->getHealthPerSoldier() << "\n";
    cout << "   - Damage : " << shieldBearer->getDamagePerSoldier() << "\n";
    cout << "   - Defence: " << shieldBearer->getDefencePerSoldier() << "\n\n" << RESET;

    cout << MAGENTA << " • Boatman: \n";
    cout << "   - Health : " << boatman->getHealthPerSoldier() << "\n";
    cout << "   - Damage : " << boatman->getDamagePerSoldier() << "\n";
    cout << "   - Defence: " << boatman->getDefencePerSoldier() << "\n\n" << RESET;

    delete infantry;
    delete shieldBearer;
    delete boatman;

    cout << endl;
}

void testPrototypePattern() {
    Infantry infantry;

    infantry.setHealthPerSoldier(110);
    infantry.setDamagePerSoldier(75);
    infantry.setDefencePerSoldier(44);
    infantry.setAmountOfSoldiersPerUnit(5);
    infantry.setUnitName("Infantry Unit 12");

    Soldiers* clonedInfantry = infantry.clonis();

    cout << endl;

    cout << CYAN << "- Prototype Pattern Test:\n\n" << RESET;

    cout << GREEN << " • Cloned Infantry:\n";
    cout << "   - Health         : " << clonedInfantry->getHealthPerSoldier() << "\n";
    cout << "   - Damage         : " << clonedInfantry->getDamagePerSoldier() << "\n";
    cout << "   - Defence        : " << clonedInfantry->getDefencePerSoldier() << "\n";
    cout << "   - No. of Soldiers: " << clonedInfantry->getAmountOfSoldiersPerUnit() << "\n";
    cout << "   - Unit Name      : " << clonedInfantry->getUnitName() << "\n\n" << RESET;

    delete clonedInfantry;
}

void testTemplateMethod() {
    Infantry infantry;
    ShieldBearer shieldBearer;
    Boatman boatman;

    cout << endl;

    cout << BLUE << "- Template Method Test:\n\n" << RESET;

    cout << YELLOW << " • Infantry:\n" << RESET;
    cout << endl;
    infantry.engage();
    infantry.disengage();
    cout << "\n";

    cout << MAGENTA << " • ShieldBearer:\n" << RESET;
    cout << endl;
    shieldBearer.engage();
    shieldBearer.disengage();
    cout << "\n";

    cout << CYAN << " • Boatman:\n" << RESET;
    boatman.engage();
    boatman.disengage();
    cout << "\n";
}

void testMementoPattern() {
    Infantry infantry;

    cout << endl;

    // Initial state
    infantry.setAttributes(152, 67, 30, 15, "Infantry Unit 23");

    // Save the initial state
    Caretaker caretaker;
    Memento* savedState1 = infantry.militusMemento();
    caretaker.addMemento(savedState1);

    // Restore and display
    infantry.vivificaMemento(caretaker.getMemento(0));
        cout << MAGENTA << "- Memento Pattern Test:\n\n" << RESET;
    cout << CYAN << " • Restored to Initial State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;



    // Modify the state
    infantry.setAttributes(120, 55, 25, 10, "Infantry Unit 23.2");
    Memento* savedState2 = infantry.militusMemento();
    caretaker.addMemento(savedState2);
    infantry.vivificaMemento(caretaker.getMemento(1));
    cout << YELLOW << " • Restored to Modified State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;


    // Further modify the state
    infantry.setAttributes(90, 40, 20, 5, "Infantry Unit 23.3");
    Memento* savedState3 = infantry.militusMemento();
    caretaker.addMemento(savedState3);
    infantry.vivificaMemento(caretaker.getMemento(2));
    cout << RED << " • Restored to Further Modified State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;
}





//====================================================================================================================
/*#include <iostream>
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

// Function Prototypes
void thankyou();
void testCalculateFunctions();
void testFactoryMethod();
void testPrototypePattern();
void testTemplateMethod();
void testMementoPattern();
void printDivider(const string& title, const string& color);

// ANSI color codes
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

int main() {

    cout << RED << BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                       Testing Main Starts                             ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n" << RESET << "\n";

    // Factory Method 1
    printDivider("Testing Factory Method 1", GREEN);
    testCalculateFunctions();
    cout << endl;

    cout << string(70, '\u25A0') << endl << endl << endl;

    // Factory Method 2
    printDivider("Testing Factory Method 2", YELLOW);
    testFactoryMethod();
    cout << endl;

    cout << string(70, '\u25CF') << endl << endl << endl;

    // Prototype Pattern
    printDivider("Testing Prototype Pattern", CYAN);
    testPrototypePattern();
    cout << endl;

    cout << string(70, '\u25B2') << endl << endl << endl;

    // Template Method
    printDivider("Testing Template Method", BLUE);
    testTemplateMethod();
    cout << endl;

    cout << string(70, '\u2665') << endl << endl << endl;

    // Memento Pattern
    printDivider("Testing Memento Pattern", MAGENTA);
    testMementoPattern();
    cout << endl;

    cout << string(70, '<>') << endl << endl << endl;

    cout << RED << BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                       Testing Main Ends                               ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n" << RESET << "\n";
    
    thankyou();

    return 0;
}

// Function to print a colored divider with a title
void printDivider(const string& title, const string& color) {
    cout << color << BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║ " << title << string(65 - title.length(), ' ') << "     ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n" << RESET << "\n";
}

void thankyou() {
    cout << endl << endl;
    cout << MAGENTA << "-------------------------------- Thank you --------------------------------" << RESET << endl << endl << endl;
}

void testCalculateFunctions() {
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    cout << endl;

    cout << GREEN << "- Testing Calculate Functions from Factory Method:\n\n" << RESET;

    // Calculate Total Health per Unit
    cout << YELLOW << " • Infantry Total Health: " << infantryFactory.calculateTotalHealthPerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Health: " << shieldBearerFactory.calculateTotalHealthPerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Health: " << boatmanFactory.calculateTotalHealthPerUnit() << '\n' << RESET;

    cout << endl;

    // Calculate Total Damage per Unit
    cout << YELLOW << " • Infantry Total Damage: " << infantryFactory.calculateTotalDamagePerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Damage: " << shieldBearerFactory.calculateTotalDamagePerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Damage: " << boatmanFactory.calculateTotalDamagePerUnit() << '\n' << RESET;

    cout << endl;

    // Calculate Total Defence per Unit
    cout << YELLOW << " • Infantry Total Defence: " << infantryFactory.calculateTotalDefencePerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Defence: " << shieldBearerFactory.calculateTotalDefencePerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Defence: " << boatmanFactory.calculateTotalDefencePerUnit() << '\n' << RESET;

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

    cout << YELLOW << "- Factory Method Test:\n\n" << RESET;

    cout << GREEN << " • Infantry: \n";
    cout << "   - Health : " << infantry->getHealthPerSoldier() << "\n";
    cout << "   - Damage : " << infantry->getDamagePerSoldier() << "\n";
    cout << "   - Defence: " << infantry->getDefencePerSoldier() << "\n\n" << RESET;

    cout << BLUE << " • ShieldBearer: \n";
    cout << "   - Health : " << shieldBearer->getHealthPerSoldier() << "\n";
    cout << "   - Damage : " << shieldBearer->getDamagePerSoldier() << "\n";
    cout << "   - Defence: " << shieldBearer->getDefencePerSoldier() << "\n\n" << RESET;

    cout << MAGENTA << " • Boatman: \n";
    cout << "   - Health : " << boatman->getHealthPerSoldier() << "\n";
    cout << "   - Damage : " << boatman->getDamagePerSoldier() << "\n";
    cout << "   - Defence: " << boatman->getDefencePerSoldier() << "\n\n" << RESET;

    delete infantry;
    delete shieldBearer;
    delete boatman;

    cout << endl;
}

void testPrototypePattern() {
    Infantry infantry;

    infantry.setHealthPerSoldier(110);
    infantry.setDamagePerSoldier(75);
    infantry.setDefencePerSoldier(44);
    infantry.setAmountOfSoldiersPerUnit(5);
    infantry.setUnitName("Infantry Unit 12");

    Soldiers* clonedInfantry = infantry.clonis();

    cout << endl;

    cout << CYAN << "- Prototype Pattern Test:\n\n" << RESET;

    cout << GREEN << " • Cloned Infantry:\n";
    cout << "   - Health         : " << clonedInfantry->getHealthPerSoldier() << "\n";
    cout << "   - Damage         : " << clonedInfantry->getDamagePerSoldier() << "\n";
    cout << "   - Defence        : " << clonedInfantry->getDefencePerSoldier() << "\n";
    cout << "   - No. of Soldiers: " << clonedInfantry->getAmountOfSoldiersPerUnit() << "\n";
    cout << "   - Unit Name      : " << clonedInfantry->getUnitName() << "\n\n" << RESET;

    delete clonedInfantry;
}

void testTemplateMethod() {
    Infantry infantry;
    ShieldBearer shieldBearer;
    Boatman boatman;

    cout << endl;

    cout << BLUE << "- Template Method Test:\n\n" << RESET;

    cout << YELLOW << " • Infantry:\n" << RESET;
    cout << endl;
    infantry.engage();
    infantry.disengage();
    cout << "\n";

    cout << MAGENTA << " • ShieldBearer:\n" << RESET;
    cout << endl;
    shieldBearer.engage();
    shieldBearer.disengage();
    cout << "\n";

    cout << CYAN << " • Boatman:\n" << RESET;
    boatman.engage();
    boatman.disengage();
    cout << "\n";
}

void testMementoPattern() {
    Infantry infantry;

    cout << endl;

    // Initial state
    infantry.setAttributes(152, 67, 30, 15, "Infantry Unit 23");

    // Save the initial state
    Caretaker caretaker;
    Memento* savedState1 = infantry.militusMemento();
    caretaker.addMemento(savedState1);

// Restore and display
    infantry.vivificaMemento(caretaker.getMemento(0));
        cout << MAGENTA << "- Memento Pattern Test:\n\n" << RESET;
    cout << CYAN << " • Restored to Initial State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;



    // Modify the state
    infantry.setAttributes(120, 55, 25, 10, "Infantry Unit 23.2");
    Memento* savedState2 = infantry.militusMemento();
    caretaker.addMemento(savedState2);
    infantry.vivificaMemento(caretaker.getMemento(1));
    cout << YELLOW << " • Restored to Modified State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;


    // Further modify the state
    infantry.setAttributes(90, 40, 20, 5, "Infantry Unit 23.3");
    Memento* savedState3 = infantry.militusMemento();
    caretaker.addMemento(savedState3);
    infantry.vivificaMemento(caretaker.getMemento(2));
    cout << RED << " • Restored to Further Modified State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;
}*/