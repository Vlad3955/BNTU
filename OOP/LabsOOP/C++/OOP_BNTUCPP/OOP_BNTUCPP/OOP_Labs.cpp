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
Runway::Runway(double l, double w, string p, int rwNum) : length(l), width(w), pavement(p), runwayNumber(rwNum){}
Runway::Runway(int rwNum)
{
	length = 300.0;
	width = 10.0;
	pavement = "";
	runwayNumber = rwNum;
}
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
	airportName = "Minsk2";
	boardNumber = 77421;
	destination = "Stambul";
	departureHour = 17;
	departureMinut = 12;
	arrivalHour = 20;
	arrivalMinut = 51;
	//runway = Runway(17);
	runway.setRunwayNumber(13);
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
void Airport::setAirportName(string _airportName)
{
	airportName = _airportName;
}
void Airport::setBoardNumber(int bNum)
{
	boardNumber = bNum;
}
void Airport::setDestination(string d_tion)
{
	destination = d_tion;
}
void Airport::setArrivalHour(int arHour)
{
	arrivalHour = arHour;
}
void Airport::setDepartureHour(int deHour)
{
	departureHour = deHour;
}
void Airport::setArrivalMinut(int arMinut)
{
	arrivalMinut = arMinut;
}
void Airport::setDepartureMinut(int deMinut)
{
	departureMinut = deMinut;
}
void Airport::setRunway(int _runway)
{
	runway.setRunwayNumber(_runway);
}
string Airport::getAirportName()
{
	return airportName;
}
int Airport::getBoardNumber()
{
	return boardNumber;
}
string Airport::getDestination()
{
	return destination;
}
int Airport::getArrivalHour()
{
	return arrivalHour;
}
int Airport::getDepartureHour()
{
	return departureHour;
}
int Airport::getArrivalMinut()
{
	return arrivalMinut;
}
int Airport::getDepartureMinut()
{
	return departureMinut;
}
Runway Airport::getRunway()
{
	return runway.getRunwayNumber();
}
void Airport::print()
{
	cout << getAirportName();
}
Airport::~Airport() 
{
	delete instAirport;
}


// LabWork 3
Customer::Customer()
{
	fullName = "";
	depositAmount = 0.0;
	validity = 0;
}
Customer::Customer(string _fullName, double _depositAmount, int _validity, Deposits _depositType) : 
fullName(_fullName), depositAmount(_depositAmount), validity(_validity), depositType(_depositType) {}
Customer::~Customer() {}

BankSystem::BankSystem() {}
BankSystem::BankSystem(string _name) : name(_name) {}
BankSystem::BankSystem(double _dollarsRate, double _rublesRate, double _euroRate) : 
dollarsRate(_dollarsRate), rublesRate(_rublesRate), euroRate(_euroRate) {}
string BankSystem::getName()
{
	return name;
}
double BankSystem::totalSumDeposits()
{
	return;
}
BankSystem::~BankSystem() {}