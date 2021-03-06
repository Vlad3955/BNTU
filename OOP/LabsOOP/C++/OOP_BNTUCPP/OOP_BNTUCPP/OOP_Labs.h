#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;
// Practicum
//=====================================================================================
//=====================================================================================
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
	string name;// ???????? ??????????
	int numDep;// ?????????? ?????????
	double	depAmount, interRate;// ????? ????????, ?????????? ??????
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
	double length, width;// ??????, ??????
	int runwayNumber;
	string pavement;// ???????? ????????
};

class Airport
{
	string airportName;
	Runway runway;// ?????????? ???????? ??????
	static Airport* instAirport; // ??????????? ????????? ???? ?????? 
	int boardNumber;// ????? ?????
	string destination;// ????? ??????????
	int arrivalHour, arrivalMinut, departureHour, departureMinut;// ????? ????????, ????? ??????.
public:
	static Airport* InstanceAirport();// ??????????? ????? ??? ????????? ????????????? ??????????(Singleton)
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
	string bankName;// ???????? ??????????
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
	Contribution(double _depositAmount);
	virtual double getDepositAmount() = 0;
	~Contribution();
protected:
	double depositAmount;
};


class ContributionUsual : public Contribution
{
public:
	ContributionUsual();
	ContributionUsual(double _depositAmount);
	virtual double getDepositAmount() override;
	~ContributionUsual();
};


class ContributionVip : public Contribution
{
public:
	ContributionVip();
	ContributionVip(double _depositAmount, double _bonusVip);
	virtual double getDepositAmount() override;
	~ContributionVip();
private:
	double bonusVip;
};


class Contributer
{
public:
	Contributer();
	Contributer(string _fullName, Contribution* _contribution);
	string getFullName();
	void setStrategy(Contribution* _contribution);
	virtual double getDepositAmount();
	~Contributer();
private:
	string fullName;
	Contribution* contribution;
};



class Bank2
{
public:
	Bank2();
	void addContributers(Contributer* _contributers);
	void information();
	~Bank2();
private:
	vector<Contributer*> contributers;
};


//=====================================================================================
//=====================================================================================
// LabWork 6

class Person
{
public:
	Person();
	Person(string _name, int _age);
	string getName();
	virtual int getAge() = 0;
	~Person();
protected:
	string name;
	int age;
};


class Student : public Person
{
public:
	Student();
	Student(string _name, int _age);
	virtual int getAge() override;
	~Student();
};


class Teacher : public Person
{
public:
	Teacher();
	Teacher(string _name, int _age);
	virtual int getAge() override;
	~Teacher();
};




