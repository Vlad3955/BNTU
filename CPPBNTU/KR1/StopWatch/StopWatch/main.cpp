#include <iostream>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	StopWatch sw;

	/*sw.Start();
	cout << "Секундомер запущен" << endl;
	sw.Show();

	Sleep(3000);
	sw.Stop();
	cout << "Секундомер остановлен спустя 3 сек" << endl;
	sw.Show();

	Sleep(5000);
	sw.Start();
	cout << "Секундомер продолжил работу спустя 5 секунд" << endl;
	sw.Show();*/


	cout << "Нажмите 1 для старта" << endl;
	int a;
	cin >> a;

	if (a == 1)
	{
		sw.Start();
		cout << "Секундомер запущен" << endl;
		sw.Show();
	}
	else
	{
		cout << "Нажмите 1 для старта" << endl;
	}
	
	cout << "Нажмите 2 для остановки" << endl;
	int b;
	cin >> b;

	if (b == 2)
	{
		sw.Stop();
		cout << "Секундомер остановлен" << endl;
		sw.Show();
	}
	else
	{
		cout << "Нажмите 2 для остановки" << endl;
	}
	

	

	cout << endl;
	return 0;
}