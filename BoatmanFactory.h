#ifndef BOATMANFACTORY_H
#define BOATMANFACTORY_H

#include "SoldierFactory.h"
#include "Boatman.h"

using namespace std;

class SoldierFactory;

class BoatmanFactory : public SoldierFactory
{
    public:
        Soldiers createUnit();
        int calculateTotalHealthPerUnit();
        int calculateTotalDamagePerUnit();
        int calculateTotalDefencePerUnit();
};

#endif