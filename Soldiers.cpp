#include "Soldiers.h"

void Soldiers::engage()
{
    prepare();
    execute();
}

void Soldiers::disengage()
{
    retreat();
    rest();
}

int Soldiers::getHealth()
{
    return healthPerSoldier;
}

int Soldiers::getDamage()
{
    return damagePerSoldier;
}

int Soldiers::getDefence()
{
    return defencePerSoldier;
}

int Soldiers::getAmountOfSoldiers()
{
    return amountOfSoldierPerUnit;
}

string Soldiers::getName()
{
    return unitName;
}

void Soldiers::setAttributes(int h, int dam, int def, int amt, string n)
{
    this->healthPerSoldier = h;
    this->damagePerSoldier = dam;
    this->defencePerSoldier = def;
    this->amountOfSoldierPerUnit = amt;
    this->unitName = n;
}

Memento* Soldiers::militusMemento()
{
    return new Memento(healthPerSoldier, damagePerSoldier, defencePerSoldier, amountOfSoldierPerUnit, unitName);
}
void Soldiers::vivificaMemento(Memento* mem)
{
    if(mem)
    {
        healthPerSoldier = mem->getAmountOfSoldierPerUnit();
        damagePerSoldier = mem->getDamagePerSoldier();
        defencePerSoldier = mem->getDefencePerSoldier();
        amountOfSoldierPerUnit = mem->getAmountOfSoldierPerUnit();
        unitName = mem->getUnitName();
    }
}