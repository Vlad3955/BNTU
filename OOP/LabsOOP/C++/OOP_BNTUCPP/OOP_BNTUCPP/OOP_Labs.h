#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// LabWork 1
class Bank
{
public:
	Bank();
	Bank(string n, int nDep, double dAmount, double iRate);
	string getName();
	int getNumDep();
	double getDepAmount();
	double getInterRate();
	double getInterPay();
	~Bank();
private:
	string name;// название учреждени€
	int numDep;// количество депозитов
	double	depAmount, interRate;// сумма депозита, процентна€ ставка
};

// LabWork 2
class Runway
{
public:
	Runway();
	Runway(int rwNum);
	Runway(double l, double w, string p, int rwNum);
	double getLength();
	double getWidth();
	string getPavement();
	void setRunwayNumber(int rwNum);
	int getRunwayNumber();
	~Runway();
private:
	double length, width;// длинна, ширина
	int runwayNumber;
	string pavement;// дорожное покрытие
};

class Airport
{
	string airportName;
	Runway runway;// переменна€ взлетной полосы
	static Airport* instAirport; // статический указатель типа Ёйрпот 
	int boardNumber;// номер борта
	string destination;// пункт назначени€
	int arrivalHour, arrivalMinut, departureHour, departureMinut;// врем€ прибыти€, врем€ убыти€.
public:
	static Airport* InstanceAirport();// статический метод дл€ выделени€ кдинственного экземпл€ра(Singleton)
	void setAirportName(string _airportName);
	void setBoardNumber(int bNum);
	void setDestination(string d_tion);
	void setArrivalHour(int arHour);
	void setDepartureHour(int deHour);
	void setArrivalMinut(int arMinut);
	void setDepartureMinut(int deMinut);
	void setRunway(int _runway);
	string getAirportName();
	int getBoardNumber();
	string getDestination();
	int getArrivalHour();
	int getDepartureHour();
	int getArrivalMinut();
	int getDepartureMinut();
	Runway getRunway();
	void print();
protected:
	Airport();
	~Airport();
};

// LabWork 3
enum Deposits {InDollars, InRubles, InEuro };

// Customer
class Customer
{
public:
	Customer();
	Customer(string _fullName, double _depositAmount, int _validity, Deposits _depositType);
	string getFullName();
	double getDepositAmount();
	int getValidity();
	Deposits getDepositType();
	void setPercentAmount(double _percentAmount);
	double getPercentAmount();
	~Customer();
private:
	string fullName;
	double depositAmount;
	int validity;
	double percentAmount;
	Deposits depositType;
};

//Bank
class BankSystem
{
public:
	BankSystem();
	BankSystem(string _bankName);
	BankSystem(double _dollarsRate, double _rublesRate, double _euroRate);
	string getBankName();
	double getDollarsRate();
	double getRublesRate();
	double getEuroRate();
	void addCustomer(string _fullName, double _depositAmount, int _validity, Deposits _depositType);
	double totalSumDeposits();
	void customersInformation();
	~BankSystem();
private:
	vector<Customer> bankCustomer;
	string bankName;// название учреждени€
	double dollarsRate, rublesRate, euroRate;
};


// LabWork 4
struct ExtraClasses
{
	string name;
	double price = 0.0;
};

class Education
{
public:
	Education();
	Education(string _name, string _address, string _workTime, 
		int _phoneNumber, int _numOfStudents, int _numOfTeachers);
	Education(string _name, string _address, string _workTime, int _phoneNumber);
	string getName();
	string getAddress();
	string getWorkTime();
	int getPhoneNumber();
	int getNumOfStudents();
	int getNumOfTeachers();
	void setExtraClass(string extraClassName, double extraClassPrice);
	ExtraClasses getExtraClass();
	~Education();
protected:
	string name, address, workTime;
	int phoneNumber, numOfStudents, numOfTeachers;
	ExtraClasses extraClass;
};

class School : public Education
{
public:
	School();
	School(string _name, string _depthStudy, string _address, string _workTime,
		int _phoneNumber, int _numOfStudents, int _numOfTeachers);
	School(string _name, string _address, string _workTime, int _phoneNumber);
	string getDepthStudy();
	~School();
private:
	string depthStudy;
};

class Kindergarten final : public Education
{
public:
	Kindergarten();
	Kindergarten(string _name, string _address, string _workTime,
		int _phoneNumber, int _numOfStudents, int _numOfTeachers, int _numOfKGTeachers);
	Kindergarten(string _name, string _address, string _workTime, int _phoneNumber);
	int getNumOfKGTeachers();
	~Kindergarten();
private:
	int numOfKGTeachers;
};


// LabWork 5
class Contribution
{
public:
	Contribution();
	string getFullName();
	virtual double getDepositAmount() = 0;
	~Contribution();
private:
	string fullName;
	double depositAmount;
};


class ContributionUsual : public Contribution
{
public:
	ContributionUsual();
	double getDepositAmount() override;
	~ContributionUsual();
private:

};


class ContributionVip : public Contribution
{
public:
	ContributionVip();
	double getDepositAmount() override;
	~ContributionVip();
private:

};



class Bank2
{
public:
	Bank2();
	~Bank2();

private:
	vector<Contribution> contributors;
};






