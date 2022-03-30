#include "OOP_Labs.h"

//class Product
//{
//public:
//	string Titel;
//	int Price;
//	Product(string t, int p)
//	{
//		Titel = t; Price = p;
//	}
//	void setTitel(string t)
//	{
//		Titel = t;
//	}
//	string getTitel()
//	{
//		return Titel;
//	}
//	void setPrice(int p)
//	{
//		Price = p;
//	}
//	int getPrice()
//	{
//		return Price;
//	}
//};
//
//
//
//class Store
//{
//public:
//	vector<Product> lstProd;
//	vector<Customer> lstCust;
//	Customer currentCust;
//	void AddProduct(string t, int p)
//	{
//		lstProd.push_back(Product(t, p));
//	}
//	void AddCustomer(string n, CustomerType ct)
//	{
//		lstCust.push_back(Customer(n, ct));
//	}
//	Customer GetCustByName(string n)
//	{
//		for (auto item : lstCust)
//		{
//			if (item.Name == n)
//			{
//				return item;
//			}
//			else
//			{
//				cout << "Error";
//			}
//		}
//	}
//	Product GetProdByTitle(string t)
//	{
//		for(auto item : lstProd)
//		{
//			if (item.Titel == t)
//			{
//				return item;
//			}
//			else
//			{
//				cout << "Error";
//			}
//		}
//	}
//	void LogIn(string n)
//	{
//		if (currentCust == null)
//			currentCust = GetCustByName(n);
//	}
//    void LogOut()
//	{
//		currentCust = nullptr;
//	}
//	void BuyProduct(string titel)
//	{
//		Product p = GetProdByTitle(titel);
//		currentCust.BuyProduct(p);
//	}
//	int GetTotalSum()
//	{
//		int sum = 0;
//		for(Customer c : lstCust)
//		{
//			for(Product p : c.lstProdOfCust)
//			{
//				sum += p.Price;
//			}
//		}
//		return sum;
//	}
//	string GetProductsByName(string
//		name)
//	{
//		Customer c = GetCustByName(name);
//		string s = «Customer:» + c.Name +
//			«\n»;
//		foreach(Product p in c.LstProdOfCust)
//		{
//			s += p.Titel + « « + p.Price +
//				«\n»;
//		}
//		return s;
//	}
//};
//
//
//
//
//enum CustomerType { VIP, usual };
//class Customer
//{
//public:
//	vector<Product> lstProdOfCust;
//	string Name;
//	CustomerType CType;
//	Customer(string n, CustomerType ct)
//	{
//		Name = n; CType = ct;
//	}
//	void setName(string n)
//	{
//		Name = n;
//	}
//	string getName()
//	{
//		return Name;
//	}
//	void setCType(CustomerType ct)
//	{
//		CType = ct;
//	}
//	CustomerType getCType()
//	{
//		return CType;
//	}
//	void BuyProduct(Product p)
//	{
//		lstProdOfCust.push_back(p);
//	}
//	int GetSum()
//	{
//		int s = 0;
//		for(Product item : lstProdOfCust)
//		{
//			s += item.Price;
//		}
//		return s;
//	}
//};

int main()
{
	//=====================================================================================
	//=====================================================================================
	// Practicum
	// LabWork1
	/*Bank b("Priorbank", 130, 350000, 4.7);
	cout << b.getInterPay() << endl;*/

	// LabWork 2
	// Ñîçäàíèå îáÚåêòà Singleton
	/*Airport* Minsk1 = Airport::InstanceAirport();
	if (Minsk1 != nullptr)
	{
		cout << "Airport name: " << Minsk1->getAirportName() << endl
			<< "Destination: " << Minsk1->getDestination() << endl
			<< "Departure time: " << Minsk1->getDepartureHour() << ":" << Minsk1->getDepartureMinut() << endl
			<< "Arrival time: " << Minsk1->getArrivalHour() << ":" << Minsk1->getArrivalMinut() << endl
			<< "Runway number: " << Minsk1->getRunway().getRunwayNumber() << endl;
	}*/

	// Ïîïûòêà ñîçäàíèå 2ãî îáúåêòà Singleton
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
	/*School school("Middle school ¹151", "Mathmatic", "Odintsova 25", "8:00 - 17:00", 2223344, 433, 28);
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
	// LabWork 1 
	/*Student student("Ivan Ivanov", 17);
	cout << "Student's name: " << student.getName() << " age: " << student.getAge() << endl;
	Teacher teacher("Sergey Sergeev", 37);
	cout << "Teacher's name: " << teacher.getName() << " age: " << teacher.getAge() << endl;*/

	//=====================================================================================
	//=====================================================================================
	// LabWork 2
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