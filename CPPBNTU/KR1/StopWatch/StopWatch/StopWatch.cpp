#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

StopWatch::StopWatch()
{
	start = false;
	create = clock();
	value = 0.0;
	started = false;
}

StopWatch::~StopWatch()
{
	cout << "����� ����� ���������: " << (clock() - create) / CLOCKS_PER_SEC << "���." << endl;
}

void StopWatch::Start()
{
	if (started)
	{
		return;
	}
	start = clock();
	started = true;
}

void StopWatch::Stop()
{
	if (!started)
	{
		return;
	}
	value += (clock() - create) / CLOCKS_PER_SEC;
	started = false;
}

void StopWatch::Show()
{
	if (started)
	{
		cout << "����� �� �����������: " << value + (clock() - create) / CLOCKS_PER_SEC << "���." << endl << endl;
	}
	else
	{
		cout << "����� �� �����������: " << value << "���." << endl << endl;
	}
}