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
//		string s = �Customer:� + c.Name +
//			�\n�;
//		foreach(Product p in c.LstProdOfCust)
//		{
//			s += p.Titel + � � + p.Price +
//				�\n�;
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
	// LabWork1
	Bank b("Priorbank", 130, 350000, 4.7);
	cout << b.getInterPay() << endl;

	// LabWork 2
	// �������� ������� Singleton
	Airport* Minsk1 = Airport::InstanceAirport();
	if (Minsk1 != nullptr)
	{
		cout << "Airport name: " << Minsk1->getAirportName() << endl
			<< "Destination: " << Minsk1->getDestination() << endl
			<< "Departure time: " << Minsk1->getDepartureHour() << ":" << Minsk1->getDepartureMinut() << endl
			<< "Arrival time: " << Minsk1->getArrivalHour() << ":" << Minsk1->getArrivalMinut() << endl
			<< "Runway number: " << Minsk1->getRunway().getRunwayNumber() << endl;
	}

	// ������� �������� 2�� ������� Singleton
	Airport* Minsk2 = Airport::InstanceAirport();
	if (Minsk2 != nullptr)
	{
		Minsk2->setDestination("Minsk2");
		cout << Minsk2->getDestination();
	}

	int h = 9;
	double df = 30.417;
	cout << static_cast<int>(h * df);

	return 0;
}