// Class implementation for 4.1. Factory Method

#include "InfantryFactory.h"
#include "SoldierFactory.h"
#include "Infantry.h"

Soldiers* InfantryFactory::createUnit() {
    return new Infantry();
}

int InfantryFactory::calculateTotalHealthPerUnit() {
    // Calculate based on an Infantry instance created by createUnit()
    Soldiers* infantry = createUnit(); 
    return infantry->getAmountOfSoldiersPerUnit() * infantry->getHealthPerSoldier();
}

int InfantryFactory::calculateTotalDamagePerUnit() {
    Soldiers* infantry = createUnit(); 
    return infantry->getAmountOfSoldiersPerUnit() * infantry->getDamagePerSoldier();
}

int InfantryFactory::calculateTotalDefencePerUnit() {
    Soldiers* infantry = createUnit(); 
    return infantry->getAmountOfSoldiersPerUnit() * infantry->getDefencePerSoldier();
}
