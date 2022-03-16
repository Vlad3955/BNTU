#include <iostream>
#include "OOP_Labs.h"


Bank::Bank(string n, int nDep, double dAmount, double iRate) : name(n), numDep(nDep), depAmount(dAmount), interRate(iRate) {}
Bank::Bank() 
{
	name = "";
	numDep = 0;
	depAmount = 0.0;
	interRate = 0.0;
}
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

// LabWork 2
// Runway
Runway::Runway() 
{
	length = 300.0;
	width = 10.0;
	pavement = "";
	runwayNumber = 11;
}
Runway::Runway(int rwNum) 
{
	runwayNumber = rwNum;
}
Runway::Runway(double l, double w, string p, int rwNum) : length(l), width(w), pavement(p), runwayNumber(rwNum){}
double Runway::getLength()
{
	return length;
}
double Runway::getWidth()
{
	return width;
}
string Runway::getPavement()
{
	return pavement;
}
void Runway::setRunwayNumber(int rwNum)
{
	runwayNumber = rwNum;
}
int Runway::getRunwayNumber()
{
	return runwayNumber;
}
Runway::~Runway() {}

// Airport
Airport* Airport::instAirport = nullptr;
Airport::Airport()
{
	boardNumber = 0;
	destination = "";
	arrivalTime = 0;
	departureTime = 0;
	runway = Runway(1);
}
//Airport::Airport(int bNum, string d_tion, int arTime, int deTime, Runway _runway) : boardNumber(bNum), destination(d_tion), arrivalTime(arTime), departureTime(deTime), runway(_runway) {}
Airport* Airport::InstanceAirport()
{
	if (instAirport == nullptr)
	{
		instAirport = new Airport();
		return instAirport;
	}
	else
	{
		return nullptr;
	}
}
void Airport::setBoardNumber(int bNum)
{
	boardNumber = bNum;
}
void Airport::setDestination(string d_tion)
{
	destination = d_tion;
}
void Airport::setArrivalTime(int arTime)
{
	arrivalTime = arTime;
}
void Airport::setDepartureTime(int deTime)
{
	departureTime = deTime;
}
void Airport::setRunway(int _runway)
{
	runway.setRunwayNumber(_runway);
}
int Airport::getBoardNumber()
{
	return boardNumber;
}
string Airport::getDestination()
{
	return destination;
}
int Airport::getArrivalTime()
{
	return arrivalTime;
}
int Airport::getDepartureTime()
{
	return departureTime;
}
Runway Airport::getRunway()
{
	return runway.getRunwayNumber();
}
void Airport::print()
{
	cout << getBoardNumber() << " " << getDestination();
}
Airport::~Airport() 
{
	delete instAirport;
}