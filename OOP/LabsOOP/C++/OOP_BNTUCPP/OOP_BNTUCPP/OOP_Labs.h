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
	//Airport(int bNum, string d_tion, int arTime, int deTime, Runway _runway);
	~Airport();
};

// LabWork 3
enum Deposits {InDollars, InRubles, InEuro};

class Customer
{
public:
	Customer();
	Customer(string _fullName, double _depositAmount, int _validity, Deposits _depositType);
	~Customer();
private:
	string fullName;
	double depositAmount;
	int validity;
	Deposits depositType;
};


class BankSystem
{
public:
	BankSystem();
	BankSystem(string _name);
	BankSystem(double _dollarsRate, double _rublesRate, double _euroRate);
	string getName();
	double totalSumDeposits();
	~BankSystem();
private:
	vector<Customer> bankCustomer;
	string name;// название учреждени€
	double dollarsRate, rublesRate, euroRate;
};
