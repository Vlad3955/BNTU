#pragma once
#include <iostream>
#include <string>

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
	string name;
	int numDep;
	double	depAmount, interRate;
};


