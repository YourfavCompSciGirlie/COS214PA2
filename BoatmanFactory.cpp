// Class implementation for 4.1. Factory Method

#include "BoatmanFactory.h"
#include "SoldierFactory.h"
#include "Boatman.h"

BoatmanFactory::BoatmanFactory() {
    cout << "Boatman factory created." << endl;
}



BoatmanFactory::~BoatmanFactory() {
    cout << "Boatman Factory destroyed."<< endl;
}



Soldiers* BoatmanFactory::createUnit() {
    return new Boatman();
}



int BoatmanFactory::calculateTotalHealthPerUnit() {
    Soldiers* boatman  = createUnit();
    return boatman->getAmountOfSoldiersPerUnit() * boatman->getHealthPerSoldier();
}



int BoatmanFactory::calculateTotalDamagePerUnit() {
    Soldiers* boatman  = createUnit();
    return boatman->getAmountOfSoldiersPerUnit() * boatman->getDamagePerSoldier();
}



int BoatmanFactory::calculateTotalDefencePerUnit() {
    Soldiers* boatman  = createUnit();
    return boatman->getAmountOfSoldiersPerUnit() * boatman->getDefencePerSoldier();
}
