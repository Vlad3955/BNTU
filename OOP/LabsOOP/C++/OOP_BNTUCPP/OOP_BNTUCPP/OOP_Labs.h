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
	string name;// �������� ����������
	int numDep;// ���������� ���������
	double	depAmount, interRate;// ����� ��������, ���������� ������
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
	double length, width;// ������, ������
	int runwayNumber;
	string pavement;// �������� ��������
};

class Airport
{
	string airportName;
	Runway runway;// ���������� �������� ������
	static Airport* instAirport; // ����������� ��������� ���� ������ 
	int boardNumber;// ����� �����
	string destination;// ����� ����������
	int arrivalHour, arrivalMinut, departureHour, departureMinut;// ����� ��������, ����� ������.
public:
	static Airport* InstanceAirport();// ����������� ����� ��� ��������� ������������� ����������(Singleton)
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
	string bankName;// �������� ����������
	double dollarsRate, rublesRate, euroRate;
};


// LabWork 4
class Education
{
public:
	Education();
	Education(string _name, string _address, string _openningTime, string _closingTime, 
		int _phoneNumber, int _numOfStudents, int _numOfTeachers);
	~Education();
protected:
	string name, address, openningTime, closingTime;
	int phoneNumber, numOfStudents, numOfTeachers;
};

class School : public Education
{
public:
	School();

	~School();
private:

};

class Kindergarten final : public Education
{
public:
	Kindergarten();

	~Kindergarten();
private:

};



