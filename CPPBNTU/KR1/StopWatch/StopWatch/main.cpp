#include <iostream>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	StopWatch sw;

	sw.Start();
	cout << "Секундомер запущен" << endl;
	sw.Show();

	Sleep(3000);
	sw.Stop();
	cout << "Секундомер остановлен спустя 3 сек" << endl;
	sw.Show();

	Sleep(5000);
	sw.Start();
	cout << "Секундомер продолжил работу спустя 5 секунд" << endl;
	sw.Show();

	cout << endl;
	return 0;
}