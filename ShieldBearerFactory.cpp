// Class implementation for 4.1. Factory Method

#include "ShieldBearerFactory.h"
#include "SoldierFactory.h"
#include "ShieldBearer.h"

Soldiers* ShieldBearerFactory::createUnit() {
    // soldiers = new ShieldBearer();
    // return soldiers;

    return new ShieldBearer();
}

int ShieldBearerFactory::calculateTotalHealthPerUnit() {
    ShieldBearer shieldbearer;
    return shieldbearer.amountOfSoldiersPerUnit * shieldbearer.healthPerSoldier;
}

int ShieldBearerFactory::calculateTotalDamagePerUnit() {
    ShieldBearer shieldbearer;
    return shieldbearer.amountOfSoldiersPerUnit * shieldbearer.damagePerSoldier;

}

int ShieldBearerFactory::calculateTotalDefencePerUnit() {
    ShieldBearer shieldbearer;
    return shieldbearer.amountOfSoldiersPerUnit * shieldbearer.defencePerSoldier;
}
