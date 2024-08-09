// Class definition for 4.1. Factory Method

#ifndef BOATMANFACTORY_H
#define BOATMANFACTORY_H

#include "SoldierFactory.h"
#include "Soldiers.h"
#include "Boatman.h"

using namespace std;

class SoldierFactory;

class BoatmanFactory : public SoldierFactory {

    public:
        Soldiers* createUnit();
        int calculateTotalHealthPerUnit();
        int calculateTotalDamagePerUnit();
        int calculateTotalDefencePerUnit();

        // Added OWN functions
        BoatmanFactory();
        ~BoatmanFactory();
};

#endif // BOATMANFACTORY_H