#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <chrono>
#include <thread>
#include "SoldierFactory.h"
#include "InfantryFactory.h"
#include "ShieldBearerFactory.h"
#include "BoatmanFactory.h"
#include "Soldiers.h"
#include "Infantry.h"
#include "ShieldBearer.h"
#include "Boatman.h"
#include "Memento.h"
#include "CareTaker.h"

using namespace std;

// Function Prototypes
void thankyou();
void testCalculateFunctions();
void testFactoryMethod();
void testPrototypePattern();
void testTemplateMethod();
void testMementoPattern();
void printDivider(const string& title, const string& color);
void displayMenu();
void displayLoading(const string& color);
void showProgressBar(int duration);

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

//======================================================================================================

void displayMenu() {
    cout << endl;
    cout << BOLD << "Please select an option:\n" << RESET;
    cout << GREEN << "1. Test Calculate Functions\n";
    cout << YELLOW << "2. Test Factory Method\n";
    cout << CYAN << "3. Test Prototype Pattern\n";
    cout << BLUE << "4. Test Template Method\n";
    cout << MAGENTA << "5. Test Memento Pattern\n";
    cout << RED << "6. Exit\n" << RESET;
    cout << endl;
    //cout << "Enter your choice: ";
}

int main() {
    cout << RED << BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                       Testing Main Starts                             ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n" << RESET << "\n";

    showProgressBar(100);
    int choice;
    bool validInput;
    do {
        displayMenu();
        validInput = false; // Reset validity flag

        while (true) {
            cout << "Enter your choice: ";
            cin >> choice;

            // Check for valid input
            if (cin.fail()) {
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << RED << "Invalid input! Please enter a number.\n" << RESET;
            } else {
                validInput = true; // Input is valid
                break;
            }
        }
        cout << endl;

        if (validInput) {
            switch(choice) {
                case 1:
                    printDivider("Testing Factory Method 1", GREEN);
                    testCalculateFunctions();
                    break;
                case 2:
                    printDivider("Testing Factory Method 2", YELLOW);
                    testFactoryMethod();
                    break;
                case 3:
                    printDivider("Testing Prototype Pattern", CYAN);
                    testPrototypePattern();
                    break;
                case 4:
                    printDivider("Testing Template Method", BLUE);
                    testTemplateMethod();
                    break;
                case 5:
                    printDivider("Testing Memento Pattern", MAGENTA);
                    testMementoPattern();
                    break;
                case 6:
                    cout << RED << "Exiting...\n" << RESET;
                    break;
                default:
                    cout << RED << "Invalid choice! Please select a valid option.\n" << RESET;
                    break;
            }

        }
    } while (choice != 6);

    thankyou();

    return 0;
}


// Function to print a colored divider with a title
void printDivider(const string& title, const string& color) {
    cout << color << BOLD << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║ " << title << string(65 - title.length(), ' ') << "     ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n" << RESET << "\n";
}

void displayLoading(const string& color) {
    cout << color << "Loading";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(300)); // Simulate loading time
    }
    cout << RESET << endl << endl;
}


void thankyou()
{
    cout << endl << endl;
    cout << MAGENTA << "-------------------------------- Thank you --------------------------------" << RESET << endl << endl << endl;
}

#include <iostream>
#include <chrono>
#include <thread>

void showProgressBar(int duration) {
    const int barWidth = 100;
    for (int i = 0; i <= barWidth; ++i) {
        std::cout << RED << BOLD << "\r[";
        int pos = barWidth * i / duration;
        for (int j = 0; j < barWidth; ++j) {
            if (j < pos)
                std::cout << "\u25CF";
            else
                std::cout << ".";
        }
        std::cout << "] " << (i * 100 / barWidth) << " %" << RESET;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;
}



void testCalculateFunctions() {
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    cout << endl;

    cout << GREEN << "- Testing Calculate Functions from Factory Method:\n\n" << RESET;

    // Calculate Total Health per Unit
    cout << YELLOW << " • Infantry Total Health: " << endl << infantryFactory.calculateTotalHealthPerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Health: " << endl << shieldBearerFactory.calculateTotalHealthPerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Health: " << endl << boatmanFactory.calculateTotalHealthPerUnit() << '\n' << RESET;

    cout << endl;

    // Calculate Total Damage per Unit
    cout << YELLOW << " • Infantry Total Damage: " << endl << infantryFactory.calculateTotalDamagePerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Damage: " << endl << shieldBearerFactory.calculateTotalDamagePerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Damage: " <<endl <<  boatmanFactory.calculateTotalDamagePerUnit() << '\n' << RESET;

    cout << endl;

    // Calculate Total Defence per Unit
    cout << YELLOW << " • Infantry Total Defence: " <<endl <<  infantryFactory.calculateTotalDefencePerUnit() << "\n\n" << RESET;
    cout << BLUE << " • ShieldBearer Total Defence: " << endl << shieldBearerFactory.calculateTotalDefencePerUnit() << "\n\n" << RESET;
    cout << MAGENTA << " • Boatman Total Defence: " << endl << boatmanFactory.calculateTotalDefencePerUnit() << '\n' << RESET;

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
    cout << endl;
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
    CareTaker careTaker;
    Memento* savedState1 = infantry.militusMemento();
    careTaker.addMemento(savedState1);

    // Restore and display
    infantry.vivificaMemento(careTaker.getMemento(0));
        cout << MAGENTA << "- Memento Pattern Test:\n\n" << RESET;
    cout << CYAN << " • Restored to Initial State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;



    // Modify the state
    infantry.setAttributes(120, 55, 25, 10, "Infantry Unit 23.2");
    Memento* savedState2 = infantry.militusMemento();
    careTaker.addMemento(savedState2);
    infantry.vivificaMemento(careTaker.getMemento(1));
    cout << YELLOW << " • Restored to Modified State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;


    // Further modify the state
    infantry.setAttributes(90, 40, 20, 5, "Infantry Unit 23.3");
    Memento* savedState3 = infantry.militusMemento();
    careTaker.addMemento(savedState3);
    infantry.vivificaMemento(careTaker.getMemento(2));
    cout << RED << " • Restored to Further Modified State:\n";
    cout << "   - Health    : " << infantry.getHealthPerSoldier() << "\n";
    cout << "   - Damage    : " << infantry.getDamagePerSoldier() << "\n";
    cout << "   - Defence   : " << infantry.getDefencePerSoldier() << "\n";
    cout << "   - Unit Name : " << infantry.getUnitName() << "\n\n" << RESET;
}

