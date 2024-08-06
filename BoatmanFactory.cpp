// Class implementation for 4.1. Factory Method

#include "BoatmanFactory.h"
#include "SoldierFactory.h"
#include "Boatman.h"

Soldiers* BoatmanFactory::createUnit() {
    // soldiers = new Boatman();
    // return soldiers;

    return new Boatman();
}

int BoatmanFactory::calculateTotalHealthPerUnit() {
    Boatman boatman;
    return boatman.amountOfSoldiersPerUnit * boatman.healthPerSoldier;
}

int BoatmanFactory::calculateTotalDamagePerUnit() {
    Boatman boatman;
    return boatman.amountOfSoldiersPerUnit * boatman.damagePerSoldier;

}

int BoatmanFactory::calculateTotalDefencePerUnit() {
    Boatman boatman;
    return boatman.amountOfSoldiersPerUnit * boatman.defencePerSoldier;
}
