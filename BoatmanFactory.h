// Class definition for 4.1. Factory Method

#ifndef BOATMANFACTORY_H
#define BOATMANFACTORY_H

#include "SoldierFactory.h"
#include "Boatman.h"

using namespace std;

class SoldierFactory;

class BoatmanFactory : public SoldierFactory {

    public:
        virtual Soldiers* createUnit();
        virtual int calculateTotalHealthPerUnit();
        virtual int calculateTotalDamagePerUnit();
        virtual int calculateTotalDefencePerUnit();

        // Added OWN functions
        BoatmanFactory();
        ~BoatmanFactory();
};

#endif // BOATMANFACTORY_H