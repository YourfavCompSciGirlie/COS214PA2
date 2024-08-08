#include "Infantry.h"

using namespace std;

void Infantry::prepare()
{
    // this is subject to change, feel free to add or remove as you may :) , this is 
    //just get a basic skeleton down before we can conclude the best way to fully 
    //implement this as best as possible

    cout<< unitName << " prepares for battle! " << endl;
    int boosters = (healthPerSoldier + defencePerSoldier) / 10;
    cout << "Booster : " << boosters<< " points to the Infantry" << endl;
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
    int recovBoost = (healthPerSoldier + amountOfSoldierPerUnit)/10;
    cout << unitName << " is resting, +" << recovBoost << " health to the infantry " << endl; 

}

    // Function for 4.2. Prototype (clone - making a copy of itself)
    // Implementation made virtual (different from the UML)
    Soldiers* Infantry::clonis()
    {
        // DEEP COPY
        return new Infantry(*this);
    }