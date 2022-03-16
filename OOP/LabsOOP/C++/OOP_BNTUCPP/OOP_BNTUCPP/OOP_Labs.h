#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
	Runway runway;// переменна€ взлетной полосы
	static Airport* instAirport; // статический указатель типа Ёйрпот 
	int boardNumber;// номер борта
	string destination;// пункт назначени€
	int arrivalTime, departureTime, _runway;// врем€ прибыти€, врем€ убыти€.
public:
	static Airport* InstanceAirport();// статический метод дл€ выделени€ кдинственного экземпл€ра(Singleton)
	void setBoardNumber(int bNum);
	void setDestination(string d_tion);
	void setArrivalTime(int arTime);
	void setDepartureTime(int deTime);
	void setRunway(int _runway);
	int getBoardNumber();
	string getDestination();
	int getArrivalTime();
	int getDepartureTime();
	Runway getRunway();
	void print();
protected:
	Airport();
	//Airport(int bNum, string d_tion, int arTime, int deTime, Runway _runway);
	~Airport();
};




