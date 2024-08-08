#include "ShieldBearer.h"

using namespace std;

void ShieldBearer::prepare()
{
    cout << unitName << " prepares for battle by forming a strong defense line "<< endl;
    int defense = (healthPerSoldier + defencePerSoldier)/10;
    cout << "Defence boost : +"<< defense << " to the Shield Bearers"<< endl;

}
void ShieldBearer::execute()
{
    cout << unitName << " push forward with their shields raised high towards the enemy forces!!" << endl;
    int battle = (defencePerSoldier>damagePerSoldier) ? 0:1;
    if(battle == 0)
    {
        cout << unitName << " gains victory over the enemy troops!! "<< endl;
    }
    else if(battle == 1)
    {
        cout << unitName << " is under intense pressure from enemy forces!! "<< endl;
    }
}
void ShieldBearer::retreat()
{
    cout << unitName << " retreats to safety swiftly.. "<< endl;
    int safety = (defencePerSoldier>damagePerSoldier)? 0:1;
    if(safety == 0)
    {
        cout << unitName << " has retreated safely far away from enemy troops "<< endl;
    }
    else{
        cout << " they cannot escape, enemy troops pursue!!!" << endl;
    }
}
void ShieldBearer::rest()
{
    int recovery = (healthPerSoldier + amountOfSoldierPerUnit) / 10;
    cout << unitName << " recovers safely away from enemy troops " << recovery <<" health"<< endl;
}

    // Function for 4.2. Prototype (clone - making a copy of itself)
    // Implementation made virtual (different from the UML)
    Soldiers* ShieldBearer::clonis()
    {
        // DEEP COPY
        return new ShieldBearer(*this);
    }
