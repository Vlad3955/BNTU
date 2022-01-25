#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void task15()
{
	int x = 5;
	int dx = 5;
	int sum = x + dx;
	cout << sum << endl;
}

void task25()
{
	float pi = 0.0f, v;
	int r = 0, h = 0;
	v = pi * r * r * h;
}

void task35()
{
	cout << "Bart Simpson" << endl;
}

void task45()
{
	int kol;
	cin >> kol;
}

void task48()
{
	int u, r;
	cin >> u >> r;
}

void task55()
{
	float a;
	cout << "���������� ������ ����." << endl;
	cout << "������� ����� ����� (��) � ������� <Enter> -> ";
	cin >> a;
	cout << "����� ����: " << a * a * a << endl;
}

void task65()
{
	float kms, cm;
	cout << "���������� ���������� ����� ����������� ��������." << endl;
	cout << "������� �������� �����:\n"
		<< "�������(���������� ���������� � ����� ����������) -> ";
	cin >> kms;
	cout << "���������� ����� ������� (��) -> ";
	cin >> cm;
	cout << "���������� ����� ������� " << cm * kms << "." << endl;
}

void task85()
{
	int year;
	cout << "������� ��� � ������� <Enter> -> ";
	cin >> year;
	if (year % 4 == 0)
	{
		cout << year << " ��� - ����������." << endl;
	}
	else
	{
		cout << year << " ��� - �� ����������." << endl;
	}
}

void task105()
{
	float width, height, square, price, total;
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
		cout << "� ������: " << total << " ���." << endl;
	}
	else
	{
		cout << "����������� ������ ��� ���������" << endl;
	}
}

void task115()
{
	for (int i = 1; i < 10; i = i + 2)
	{
		cout << i << "\t" << i * i << endl;
	}
}

void task151()
{
	float x1, x2; //������� �������
	float h = 0; // ���
	int n = 0;  // ���������� ����������
	float x; // ��������
	float y = 0; // ���������



	cout << "������������ ���������� ���������." << endl;
	cout << "������ ������� ��������� -> ";
	cin >> x1;
	cout << "������� ������� ��������� -> ";
	cin >> x2;
	cout << "K��������� ���������� -> ";
	cin >> n;

	h = (x2 - x1) / n;// �������  ����
	x = x1;
	int i = 0;
	do
	{
		y += (1 / log(x));
		x += h;
		i++;
	} while (i != n);
	cout << "�������� ���������: " << h * y << endl;
}

void task162()
{
	int max = 0, min = 0, average = 0;
	const int size = 10;
	int arr[size];
	cout << "������� �������������� ��� ����� min � max ��������.\n"
		<< "������� ������(10 ����� ����� � ����� ������)-> " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	min = arr[0];
	max = arr[0];
	for (int i = 0; i < size; i++)
	{

		if (arr[i] > max)
		{
			max = arr[i];
		}

		if (arr[i] < min)
		{
			min = arr[i];
		}
	}


	for (int i = 0; i < size; i++)
	{
		if (arr[i] != max && arr[i] != min)
		{
			average += arr[i];
		}
	}
	cout << "����������� �������: " << min << endl;
	cout << "������������ �������: " << max << endl;
	cout << "������� �����. ��� ����� min � ��� ��������: " << average / (size - 2) << endl;
}

void task174()
{
	const int ROWS = 3; // ���-�� �����
	const int COLS = 5; // ���-�� ��������


	int arr[ROWS][COLS]; // ������
	int s[COLS]; //c���a ���������
	int i, j;
	cout << "\n������� ������\n";
	cout << "����� ����� ��������� ������ ������,";
	cout << "\n5 ����� �����, ��������� <Enter>\n";
	for (i = 0; i < ROWS; i++) // ROWS �����
	{
		cout << "-> ";
		for (j = 0; j < COLS; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << "\n��������� ������\n";
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	//������� ������ s
	for (i = 0; i < ROWS; i++)
	{
		s[i] = 0;
	}

	// ���������
	for (i = 0; i < ROWS; i++)// ��� ������� �������
	{
		for (j = 0; j < COLS; j++) // ��������� ��-��
		{
			s[i] += arr[i][j];
		}
	}

	cout << "............................ \n";

	for (i = 0; i < ROWS; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void task191()
{
	bool flag = false;
	char st[20]; // ������
	int i, n; // ����� ������������ �������
	cout << "\n������� ����� -> ";
	cin >> st;
	n = strlen(st);
	i = 0;
	while (i < n)
	{
		if (st[i] == '\0')
		{
			break;
		}


		if ((st[i] != '0') && (st[i] != '1'))
		{
			flag = true;
			break;
		}
		i++;
	}

	if (!flag)
	{
		cout << "��� �������� �����";
	}
	else
	{

		cout << "�� �������� �������� ������.\n";
	}
}



int main()
{
	setlocale(LC_ALL, "ru");
	//task35();
	//task55();
	//task65();
	//task85();
	//task105();
	//task115();
	//task151();
	//task162();
	//task174();
	//task191();
return 0;
}