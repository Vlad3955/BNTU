#include "OOP_Labs.h"
//#include <iostream>
//#include <string>
//using namespace std;

int main()
{
	Bank b("Priorbank", 130, 350000, 4.7);
	cout << b.getInterPay() << endl;

	Airport* Minsk1 = Airport::InstanceAirport();
	if (Minsk1 != nullptr)
	{
		Minsk1->setRunway(11);
		cout << Minsk1->getRunway();
	}

	Airport* Minsk2 = Airport::InstanceAirport();
	if (Minsk2 != nullptr)
	{
		Minsk2->setDestination("Minsk2");
		cout << Minsk2->getDestination();
	}

	return 0;
}