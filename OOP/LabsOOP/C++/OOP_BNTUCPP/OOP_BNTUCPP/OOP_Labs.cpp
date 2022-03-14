#include <iostream>
#include "OOP_Labs.h"


Bank::Bank() {}
Bank::Bank(string n, int nDep, double dAmount, double iRate) : name(n), numDep(nDep), depAmount(dAmount), interRate(iRate) {}
string Bank::getName()
{
	return name;
}
int Bank::getNumDep()
{
	return numDep;
}
double Bank::getDepAmount()
{
	return depAmount;
}
double Bank::getInterRate()
{
	return interRate;
}
double Bank::getInterPay()
{
	return ((depAmount * interRate * 273 / 365) / 100);
}
Bank::~Bank() {}
