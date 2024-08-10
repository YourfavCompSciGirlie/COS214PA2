// Class implementation for 4.1. Factory Method

#include "ShieldBearerFactory.h"
#include "SoldierFactory.h"
#include "ShieldBearer.h"

ShieldBearerFactory::ShieldBearerFactory() {
    cout << "ShieldBearer Factory created." << endl;
}



ShieldBearerFactory::~ShieldBearerFactory() {
    cout << "ShieldBearer Factory destroyed." << endl;
}



Soldiers* ShieldBearerFactory::createUnit() {
    return new ShieldBearer();
}



int ShieldBearerFactory::calculateTotalHealthPerUnit() {
    Soldiers* shieldbearer  = createUnit();
    return shieldbearer->getAmountOfSoldiersPerUnit() * shieldbearer->getHealthPerSoldier();
}



int ShieldBearerFactory::calculateTotalDamagePerUnit() {
    Soldiers* shieldbearer  = createUnit();
    return shieldbearer->getAmountOfSoldiersPerUnit() * shieldbearer->getDamagePerSoldier();
}



int ShieldBearerFactory::calculateTotalDefencePerUnit() {
    Soldiers* shieldbearer  = createUnit();
    return shieldbearer->getAmountOfSoldiersPerUnit() * shieldbearer->getDefencePerSoldier();
}