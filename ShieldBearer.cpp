#include "ShieldBearer.h"

using namespace std;

void ShieldBearer::prepare()
{

}
void ShieldBearer::execute()
{

}
void ShieldBearer::retreat()
{

}
void ShieldBearer::rest()
{

}

    // Function for 4.2. Prototype (clone - making a copy of itself)
    // Implementation made virtual (different from the UML)
    Soldiers* ShieldBearer::clonis()
    {
        // DEEP COPY
        return new ShieldBearer(*this);
    }
