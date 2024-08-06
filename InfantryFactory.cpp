// Class implementation for 4.1. Factory Method

#include "InfantryFactory.h"
#include "SoldierFactory.h"
#include "Infantry.h"

Soldiers* InfantryFactory::createUnit() {
    // soldiers = new Infantry();
    // return soldiers;

    return new Infantry();
}

int InfantryFactory::calculateTotalHealthPerUnit() {
    Infantry infantry;
    return infantry.amountOfSoldiersPerUnit * infantry.healthPerSoldier;
}

int InfantryFactory::calculateTotalDamagePerUnit() {
    Infantry infantry;
    return infantry.amountOfSoldiersPerUnit * infantry.damagePerSoldier;

}

int InfantryFactory::calculateTotalDefencePerUnit() {
    Infantry infantry;
    return infantry.amountOfSoldiersPerUnit * infantry.defencePerSoldier;
}
