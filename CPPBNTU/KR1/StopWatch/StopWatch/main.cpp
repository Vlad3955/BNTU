#include <iostream>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	StopWatch sw;

	sw.Start();
	cout << "���������� �������" << endl;
	sw.Show();

	Sleep(3000);
	sw.Stop();
	cout << "���������� ���������� ������ 3 ���" << endl;
	sw.Show();

	Sleep(5000);
	sw.Start();
	cout << "���������� ��������� ������ ������ 5 ������" << endl;
	sw.Show();

	cout << endl;
	return 0;
}