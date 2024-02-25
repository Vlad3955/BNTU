#include "OOP_Labs.h"



int main()
{
	//=====================================================================================
	//=====================================================================================
	// Practicum
	// LabWork1
	/*Bank b("Priorbank", 130, 350000, 4.7);
	cout << b.getInterPay() << endl;*/

	// LabWork 2
	// Создание обЪекта Singleton
	/*Airport* Minsk1 = Airport::InstanceAirport();
	if (Minsk1 != nullptr)
	{
		cout << "Airport name: " << Minsk1->getAirportName() << endl
			<< "Destination: " << Minsk1->getDestination() << endl
			<< "Departure time: " << Minsk1->getDepartureHour() << ":" << Minsk1->getDepartureMinut() << endl
			<< "Arrival time: " << Minsk1->getArrivalHour() << ":" << Minsk1->getArrivalMinut() << endl
			<< "Runway number: " << Minsk1->getRunway().getRunwayNumber() << endl;
	}*/

	// Попытка создание 2го объекта Singleton
	/*Airport* Minsk2 = Airport::InstanceAirport();
	if (Minsk2 != nullptr)
	{
		Minsk2->setDestination("Minsk2");
		cout << Minsk2->getDestination();
	}*/

	

	// LabWork3
	/*BankSystem customers;
	customers.addCustomer("Ivan Ivaniv", 350000, 9, InDollars);
	customers.addCustomer("Sergey Sergeev", 350000, 9, InRubles);
	customers.addCustomer("Anton Antonov", 350000, 9, InEuro);
	customers.customersInformation();*/

	// LabWork 4
	/*School school("Middle school №151", "Mathmatic", "Odintsova 25", "8:00 - 17:00", 2223344, 433, 28);
	school.setExtraClass("Math", 22.5);
	cout << school.getExtraClass().name << " " << school.getExtraClass().price;*/

	// LabWork 5
	/*Contributer* contributer1 = new Contributer("Vitold Ivanov", new ContributionVip(3000, 40));
	contributer1->setStrategy(new ContributionUsual( 2500));
	Bank2 bank;
	bank.addContributers(contributer1);
	Contributer* contributer2 = new Contributer("Vlad Govrilov", new ContributionUsual(300));
	contributer2->setStrategy(new ContributionVip(250, 25));
	bank.addContributers(contributer2);
	bank.information();*/
	//=====================================================================================
	//=====================================================================================
	// LabWork 6 
	/*Student student("Ivan Ivanov", 17);
	cout << "Student's name: " << student.getName() << " age: " << student.getAge() << endl;
	Teacher teacher("Sergey Sergeev", 37);
	cout << "Teacher's name: " << teacher.getName() << " age: " << teacher.getAge() << endl;*/

	//=====================================================================================
	//=====================================================================================
	// LabWork 7
	/*const int N = 256;
	char line[N];
	cin.getline(line, N);

	map<string, int> dictionary;
    #pragma warning(disable : 4996)
	for (char* p = strtok(line, " -.,/!?"); p != nullptr; p = strtok(nullptr, " -.,/!?"))
	{
		string word(p);
		auto it = dictionary.find(word);
		if (it != dictionary.end())
		{
			++it->second;
		}
		else
		{
			dictionary.emplace_hint(it, move(word), 1);
		}
	}

	for (auto& iter : dictionary)
	{
		cout << iter.first << "\t" << iter.second << '\n';
	}*/

	return 0;
}