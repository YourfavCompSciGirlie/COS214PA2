#ifndef INFANTRYFACTORY_H
#define INFANTRYFACTORY_H

#include "SoldierFactory.h"
#include "Soldiers.h"
#include "Infantry.h"

using namespace std;

class SoldierFactory;

class InfantryFactory : public SoldierFactory{
    public:
        Soldiers createUnit();
        int calculateTotalHealthPerUnit();
        int calculateTotalDamagePerUnit();
        int calculateTotalDefencePerUnit();
};
#endif