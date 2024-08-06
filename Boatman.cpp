#include "Boatman.h"

using namespace std;

void Boatman::prepare()
{

}
void Boatman::execute()
{

}
void Boatman::retreat()
{

}
void Boatman::rest()
{

}

    // Function for 4.2. Prototype (clone - making a copy of itself)
    // Implementation made virtual (different from the UML)
    Soldiers* Boatman::clonis()
    {
        // DEEP COPY
        return new Boatman(*this);
    }
