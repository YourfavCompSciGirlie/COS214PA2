#include "Boatman.h"

using namespace std;

void Boatman::prepare()
{
    cout << unitName << " prepares for battle!!!" << endl;
    cout << "Boatmen position their boats... " << endl;
    int boost= (healthPerSoldier + defencePerSoldier)/10;
    cout << boost << " points to the units " << endl; 
}
void Boatman::execute()
{
    cout << unitName << " emerge from the river. The war begins as boatmen launch attacks "<< endl;
    int battle = (damagePerSoldier>defencePerSoldier) ? 0:2;
    if(battle ==0)
    {
        cout << unitName << " have declared victory over the enemy troops... "<< endl;
    }
    else if(battle == 1)
    {
        cout << " its not looking good for " << unitName;
    }
    else{
        cout << unitName << " is losing hards to the enemy troops" << endl;
    }
}
void Boatman::retreat()
{
    cout << unitName << " retreats to safety.. "<< endl;
    int safety = (defencePerSoldier>damagePerSoldier)? 0:1;
    if(safety == 0)
    {
        cout << unitName << " has retreated safely far away from enemy troops "<< endl;
    }
    else{
        cout << " they cannot escape" << endl;
    }
}
void Boatman::rest()
{
    int recovery = (healthPerSoldier + amountOfSoldierPerUnit) / 10;
    cout << unitName << " recovers safely away from enemy troops " << recovery <<" health"<< endl;
}

    // Function for 4.2. Prototype (clone - making a copy of itself)
    // Implementation made virtual (different from the UML)
    Soldiers* Boatman::clonis()
    {
        // DEEP COPY
        return new Boatman(*this);
    }
