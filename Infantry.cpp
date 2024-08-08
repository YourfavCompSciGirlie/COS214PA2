#include "Infantry.h"

using namespace std;

void Infantry::prepare()
{
    // this is subject to change, feel free to add or remove as you may :) , this is 
    //just get a basic skeleton down before we can conclude the best way to fully 
    //implement this as best as possible

    cout<< unitName << " prepares for battle! " << endl;
    int boosters = (healthPerSoldier + defencePerSoldier) / 10;
    cout << "Booster : +" << boosters<< " points to the Infantry" << endl;
}
void Infantry::execute()
{
    cout << unitName << "charges towards the enemy!!" << endl;
    cout << "The infantry charge at the enemy with spears raised high. " << endl;
    int battleCounter = (damagePerSoldier > defencePerSoldier) ? 0:2;
    if(battleCounter == 0)
    {
        cout << unitName << " wins the battle! Enemies are retreating..." << endl;
    }
    else if(battleCounter == 1)
    {
        cout << "It's not looking good for any one of the sides... " << endl;
    }
    else{
        cout << unitName << " is losing this one badly. " << endl;
    }
}
void Infantry::retreat()
{
    cout << unitName << " retreats to safer grounds. " << endl;
    int safety = (defencePerSoldier > damagePerSoldier) ? 0:1;
    if(safety == 0)
    {
        cout << unitName << " has successfully retreated away from enemy forces. " << endl;

    }
    else{
        cout << "Enemy troops pursue faster..." << endl;
    }

}
void Infantry::rest()
{
    int recovBoost = (healthPerSoldier + amountOfSoldiersPerUnit)/10;
    cout << unitName << " is resting, +" << recovBoost << " health points to the infantry " << endl; 

}


// Added edited (default) constructor for 4.1. Factory Method to set default values when creating units and soldiers
Infantry::Infantry() {
        healthPerSoldier = 100;
        damagePerSoldier = 50;
        defencePerSoldier = 30;
        amountOfSoldiersPerUnit = 10;
        unitName = "Infantry Unit";

        std::cout << "Infantry Soldier has been created with default values.\n";
        std::cout << "Health: " << healthPerSoldier << ", Damage: " << damagePerSoldier << ", Defence: " << defencePerSoldier << '\n';
}


// Function for 4.2. Prototype (clone - making a copy of itself)
// Implementation made virtual (different from the UML)
Soldiers* Infantry::clonis()
{
    // DEEP COPY
    return new Infantry(*this);
}

Infantry::~Infantry()
{
    cout<< "Infantry has been destroyed."<< endl; 
}

void Infantry::engage()
{
    prepare();
    execute();
}
void Infantry::disengage()
{
    retreat();
    rest();
}