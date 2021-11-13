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
	cout << "Вычисление объема куба." << endl;
	cout << "Введите длину ребра (см) и нажните <Enter> -> ";
	cin >> a;
	cout << "Объем куба: " << a * a * a << endl;*/

//Task65
//=================================================================
	/*float kms, cm;
	cout << "Вычисление расстояния между населенными пунктами." << endl;
	cout << "Введите исходные данше:\n"
		 << "Масштаб(количество километров в одном сантиметре) -> ";
	cin >> kms;
	cout << "Расстояние между точками (см) -> ";
	cin >> cm;
	cout << "Расстояние между точками " << cm * kms << "." << endl;*/

//Task 85
//=================================================================
	/*int year;
	cout << "Введите год и нажмите <Errter> -> ";
	cin >> year;
	if (year % 4 == 0)
	{
		cout << year << " год - високосный." << endl;
	}
	else
	{
		cout << year << " год - не високосный." << endl;
	}*/

//task95
//===========================================================
	/*float width, height, square, price, total;
		int material;
	cout << "Жалюзи:" << endl;
	cout << "Ширина (см) -> ";
	cin >> width;
	cout << "Высота (см) -> ";
	cin >> height;
	cout << "Материал:\n"
		<< "1 - пластик\n"
		<< "2 - текстиль\n"
		<< "3 - алиминий\n"
		<< "Ваш выбор -> ";
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

	cout << "Ваш выбор -> " << material << endl;

	square = (width * height) / 10000;
	total = square * price;

	if (price != 0)
	{
		cout << "Цена за кв. м: " << price << endl;
		cout << "Площадь: " << square << "кв. м." << endl;
		cout << "К оплате: " << total << endl;
	}
	else
	{
		cout << "Неправильно указан код материала" << endl;
	}*/

}