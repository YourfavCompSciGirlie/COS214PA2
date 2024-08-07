// Class implementation for 4.1. Factory Method

#include "InfantryFactory.h"
#include "SoldierFactory.h"
#include "Infantry.h"

Soldiers* InfantryFactory::createUnit() {
    return new Infantry();
}

int InfantryFactory::calculateTotalHealthPerUnit() {
    Infantry infantry;
    return infantry.getAmountOfSoldiersPerUnit() * infantry.getHealthPerSoldier();
}

int InfantryFactory::calculateTotalDamagePerUnit() {
    Infantry infantry;
    return infantry.getAmountOfSoldiersPerUnit() * infantry.getDamagePerSoldier();

}

int InfantryFactory::calculateTotalDefencePerUnit() {
    Infantry infantry;
    return infantry.getAmountOfSoldiersPerUnit() * infantry.getDefencePerSoldier();
}
