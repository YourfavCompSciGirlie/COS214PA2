// Class definition for 4.1. Factory Method

#ifndef SHIELDBEARERFACTORY_H
#define SHIELDBEARERFACTORY_H

#include "SoldierFactory.h"
#include "ShieldBearer.h"

using namespace std;

class SoldierFactory;

class ShieldBearerFactory : public SoldierFactory {

    public:
        virtual Soldiers* createUnit();
        virtual int calculateTotalHealthPerUnit();
        virtual int calculateTotalDamagePerUnit();
        virtual int calculateTotalDefencePerUnit();

        // Added OWN functions
        ShieldBearerFactory();
        ~ShieldBearerFactory();
};

#endif // SHIELDBEARERFACTORY_H