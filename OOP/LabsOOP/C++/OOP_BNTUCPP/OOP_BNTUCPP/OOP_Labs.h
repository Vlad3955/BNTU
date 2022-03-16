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
	string name;// �������� ����������
	int numDep;// ���������� ���������
	double	depAmount, interRate;// ����� ��������, ���������� ������
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
	double length, width;// ������, ������
	int runwayNumber;
	string pavement;// �������� ��������
};

class Airport
{
	Runway runway;// ���������� �������� ������
	static Airport* instAirport; // ����������� ��������� ���� ������ 
	int boardNumber;// ����� �����
	string destination;// ����� ����������
	int arrivalTime, departureTime, _runway;// ����� ��������, ����� ������.
public:
	static Airport* InstanceAirport();// ����������� ����� ��� ��������� ������������� ����������(Singleton)
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




