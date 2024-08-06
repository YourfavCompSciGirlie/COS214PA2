#include "Infantry.h"

using namespace std;

void Infantry::prepare()
{
    // this is subject to change, feel free to add or remove as you may :) , this is 
    //just get a basic skeleton down before we can conclude the best way to fully 
    //implement this as best as possible

    cout<< getName() << " prepares for battle! " << endl;
    int boosters = (getHealth() + getDefence()) / 10;
    cout << "Booster : " << boosters<< " points to the Infantry" << endl;
}
void Infantry::execute()
{

}
void Infantry::retreat()
{

}
void Infantry::rest()
{

}

    // Function for 4.2. Prototype (clone - making a copy of itself)
    // Implementation made virtual (different from the UML)
    Soldiers* Infantry::clonis()
    {
        // DEEP COPY
        return new Infantry(*this);
    }