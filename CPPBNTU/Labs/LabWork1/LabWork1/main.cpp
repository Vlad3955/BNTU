#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
//Task 15
//=================================================================
	//int x = 5;
	//int dx = 5;
	//int sum = x + dx;
	//cout << sum << endl;

//Task 25
//=================================================================
	//float pi, v;
	//int r, h;
	//v = pi * r * r * h;

//Task 35
//=================================================================
	//cout << "Bart Simpson" << endl;

//Task 45
//=================================================================
	//int kol;
	//cin >> kol;


//Task 48
//=================================================================
	//int u, r;
	//cin >> u >> r;

//Task 55
//=================================================================
	/*float a;
	cout << "���������� ������ ����." << endl;
	cout << "������� ����� ����� (��) � ������� <Enter> -> ";
	cin >> a;
	cout << "����� ����: " << a * a * a << endl;*/

//Task65
//=================================================================
	/*float kms, cm;
	cout << "���������� ���������� ����� ����������� ��������." << endl;
	cout << "������� �������� �����:\n"
		 << "�������(���������� ���������� � ����� ����������) -> ";
	cin >> kms;
	cout << "���������� ����� ������� (��) -> ";
	cin >> cm;
	cout << "���������� ����� ������� " << cm * kms << "." << endl;*/

//Task 85
//=================================================================
	/*int year;
	cout << "������� ��� � ������� <Errter> -> ";
	cin >> year;
	if (year % 4 == 0)
	{
		cout << year << " ��� - ����������." << endl;
	}
	else
	{
		cout << year << " ��� - �� ����������." << endl;
	}*/

//task95
//===========================================================
	/*float width, height, square, price, total;
		int material;
	cout << "������:" << endl;
	cout << "������ (��) -> ";
	cin >> width;
	cout << "������ (��) -> ";
	cin >> height;
	cout << "��������:\n"
		<< "1 - �������\n"
		<< "2 - ��������\n"
		<< "3 - ��������\n"
		<< "��� ����� -> ";
	cin >> material;
	switch (material)
	{
	case 1:
		price = 220;
		break;
	case 2:
		price = 280;
		break;
	case 3:
		price = 350;
		break;
	default:
		price = 0;
		break;
	}

	cout << "��� ����� -> " << material << endl;

	square = (width * height) / 10000;
	total = square * price;

	if (price != 0)
	{
		cout << "���� �� ��. �: " << price << endl;
		cout << "�������: " << square << "��. �." << endl;
		cout << "� ������: " << total << endl;
	}
	else
	{
		cout << "����������� ������ ��� ���������" << endl;
	}*/

}