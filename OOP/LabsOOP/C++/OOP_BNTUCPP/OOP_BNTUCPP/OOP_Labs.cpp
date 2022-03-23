#include <iostream>
#include "OOP_Labs.h"


Bank::Bank(string n, int nDep, double dAmount, double iRate) 
	: name(n), numDep(nDep), depAmount(dAmount), interRate(iRate) {}
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
Runway::Runway(double l, double w, string p, int rwNum) 
	: length(l), width(w), pavement(p), runwayNumber(rwNum){}
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
// Customer
Customer::Customer()
{
	fullName = "";
	depositAmount = 0.0;
	validity = 0;
	percentAmount = 0.0;
}
Customer::Customer(string _fullName, double _depositAmount, int _validity, Deposits _depositType) 
	: fullName(_fullName), depositAmount(_depositAmount), validity(_validity), depositType(_depositType) 
{
	percentAmount = 0.0;
}
string Customer::getFullName()
{
	return fullName;
}
double Customer::getDepositAmount()
{
	return depositAmount;
}
int Customer::getValidity()
{
	return validity;
}
Deposits Customer::getDepositType()
{
	return depositType;
}
void Customer::setPercentAmount(double _percentAmount)
{
	percentAmount = _percentAmount;
}
double Customer::getPercentAmount()
{
	return percentAmount;
}
Customer::~Customer() {}

// Bank
BankSystem::BankSystem() 
{
	bankName = "Priorbank";
	dollarsRate = 4.7;
	rublesRate = 9.4;
	euroRate = 3.9;
}
BankSystem::BankSystem(string _bankName) : bankName(_bankName) 
{
	bankName = "Priorbank";
	dollarsRate = 4.7;
	rublesRate = 9.4;
	euroRate = 3.9;
}
BankSystem::BankSystem(double _dollarsRate, double _rublesRate, double _euroRate) 
	: dollarsRate(_dollarsRate), rublesRate(_rublesRate), euroRate(_euroRate) 
{
	bankName = "Priorbank";
	dollarsRate = 4.7;
	rublesRate = 9.4;
	euroRate = 3.9;
}
double BankSystem::getDollarsRate()
{
	return dollarsRate;
}
double BankSystem::getRublesRate()
{
	return rublesRate;
}
double BankSystem::getEuroRate()
{
	return euroRate;
}
string BankSystem::getBankName()
{
	return bankName;
}
void BankSystem::addCustomer(string _fullName, double _depositAmount, int _validity, Deposits _depositType)
{
	bankCustomer.push_back(Customer(_fullName, _depositAmount, _validity, _depositType));
}
void BankSystem::customersInformation()
{
	double totalDollarsSum = 0;
	double totalRublesSum = 0;
	double totalEuroSum = 0;
	for (auto &it : bankCustomer)
	{
		if (it.getDepositType() == 0)
		{
			it.setPercentAmount((it.getDepositAmount() * dollarsRate * static_cast<int>(it.getValidity() * 30.417) / 365) / 100);
			cout << "Deposit in dollars" << endl;
			totalDollarsSum += it.getPercentAmount();
		}
		else if (it.getDepositType() == 1)
		{
			it.setPercentAmount((it.getDepositAmount() * rublesRate * static_cast<int>(it.getValidity() * 30.417) / 365) / 100);
			cout << "Deposit in rubles" << endl;
			totalRublesSum += it.getPercentAmount();
		}
		else
		{
			it.setPercentAmount((it.getDepositAmount() * euroRate * static_cast<int>(it.getValidity() * 30.417) / 365) / 100);
			cout << "Deposit in euro" << endl;
			totalEuroSum += it.getPercentAmount();
		}
	   cout << "Full name of the client: " << it.getFullName() << endl
			<< "Deposit amount: " << it.getDepositAmount() << endl
			<< "Validity: " << it.getValidity() << endl 
		    << "Percent amount: " << it.getPercentAmount() << endl << endl;
	}
	cout << "Total in dollars: " << totalDollarsSum << endl
		 << "Total in rubles: " << totalRublesSum << endl
		 << "Total in euro: " << totalEuroSum << endl;
}
BankSystem::~BankSystem() {}

// LabWork 4
Education::Education()
{
	name = ""; 
	address = "";
	workTime = "";
	phoneNumber = 0;
	numOfStudents = 0; 
	numOfTeachers = 0;
	this->extraClass.name = "";
	this->extraClass.price = 0.0;
}
Education::Education(string _name, string _address, string _workTime,
	int _phoneNumber, int _numOfStudents, int _numOfTeachers)
	: name(_name), address(_address), workTime(_workTime),
	phoneNumber(_phoneNumber), numOfStudents(_numOfStudents), numOfTeachers(_numOfTeachers)
{
	name = "";
	address = "";
	workTime = "";
	phoneNumber = 0;
	numOfStudents = 0;
	numOfTeachers = 0;
	this->extraClass.name = "";
	this->extraClass.price = 0.0;
}
Education::Education(string _name, string _address, string _workTime,
	int _phoneNumber) : name(_name), address(_address), workTime(_workTime),
	phoneNumber(_phoneNumber) 
{
	name = "";
	address = "";
	workTime = "";
	phoneNumber = 0;
	numOfStudents = 0;
	numOfTeachers = 0;
	this->extraClass.name = "";
	this->extraClass.price = 0.0;
}
string Education::getName()
{
	return name;
}
string Education::getAddress()
{
	return address;
}
string Education::getWorkTime()
{
	return workTime;
}
int Education::getPhoneNumber()
{
	return phoneNumber;
}
int Education::getNumOfStudents()
{
	return numOfStudents;
}
int Education::getNumOfTeachers()
{
	return numOfStudents;
}
void Education::setExtraClass(string extraClassName, double extraClassPrice)
{
	this->extraClass.name = extraClassName;
	this->extraClass.price = extraClassPrice;
}
ExtraClasses Education::getExtraClass()
{
	return this->extraClass;
}
Education::~Education() {}

School::School()
{

}
School::School(string _name, string _depthStudy, string _address, string _workTime,
	int _phoneNumber, int _numOfStudents, int _numOfTeachers) 
	: Education(_name, _address, _workTime,_phoneNumber, _numOfStudents, _numOfTeachers), depthStudy(_depthStudy) {}
School::School(string _name, string _address, string _workTime, int _phoneNumber) 
	: Education(_name, _address, _workTime, _phoneNumber) {}
string School::getDepthStudy()
{
	return depthStudy;
}
School::~School() {}

Kindergarten::Kindergarten()
{
	numOfKGTeachers = 0;
}
Kindergarten::Kindergarten(string _name, string _address, string _workTime,
	int _phoneNumber, int _numOfStudents, int _numOfTeachers, int _numOfKGTeachers) 
	: Education(_name, _address, _workTime,_phoneNumber, _numOfStudents, _numOfTeachers), numOfKGTeachers(_numOfKGTeachers) 
{
	numOfKGTeachers = 0;
}
Kindergarten::Kindergarten(string _name, string _address, string _workTime, int _phoneNumber) 
{
	numOfKGTeachers = 0;
}
int Kindergarten::getNumOfKGTeachers()
{
	return numOfKGTeachers;
}
Kindergarten::~Kindergarten() {}

// LabWork 5
Bank2::Bank2()
{
}

Bank2::~Bank2()
{
}

Contributor::Contributor()
{
}

Contributor::~Contributor()
{
}

ContributerUsual::ContributerUsual()
{
}

ContributerUsual::~ContributerUsual()
{
}

ContributerVip::ContributerVip()
{
}

ContributerVip::~ContributerVip()
{
}