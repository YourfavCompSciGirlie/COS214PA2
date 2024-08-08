// Class implementation for 4.1. Factory Method

#include "ShieldBearerFactory.h"
#include "SoldierFactory.h"
#include "ShieldBearer.h"

ShieldBearerFactory::ShieldBearerFactory()
{
    cout << "ShieldBearer Factory created " << endl;
}
ShieldBearerFactory::~ShieldBearerFactory()
{
    cout << "ShieldBearer Factory destroyed" << endl;
}

Soldiers* ShieldBearerFactory::createUnit() {
    return new ShieldBearer();
}

int ShieldBearerFactory::calculateTotalHealthPerUnit() {
    ShieldBearer shieldbearer;
    return shieldbearer.getAmountOfSoldiersPerUnit() * shieldbearer.getHealthPerSoldier();
}

int ShieldBearerFactory::calculateTotalDamagePerUnit() {
    ShieldBearer shieldbearer;
    return shieldbearer.getAmountOfSoldiersPerUnit() * shieldbearer.getDamagePerSoldier();

}

int ShieldBearerFactory::calculateTotalDefencePerUnit() {
    ShieldBearer shieldbearer;
    return shieldbearer.getAmountOfSoldiersPerUnit() * shieldbearer.getDefencePerSoldier();
}
