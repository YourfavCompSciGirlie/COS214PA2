// Class definition for 4.1. Factory Method

#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "Soldiers.h"

using namespace std;

class SoldierFactory {

    private:
        Soldiers* soldiers;
    
    protected:
        virtual Soldiers* createUnit() = 0;
        virtual int calculateTotalHealthPerUnit() = 0;
        virtual int calculateTotalDamagePerUnit() = 0;
        virtual int calculateTotalDefencePerUnit() = 0;

    public:
        // Added OWN functions
        virtual ~SoldierFactory();
        SoldierFactory();
};

#endif // SOLDIERFACTORY_H