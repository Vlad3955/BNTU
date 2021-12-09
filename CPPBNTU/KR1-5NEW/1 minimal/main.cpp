#include <iostream>
#include <Windows.h>
class Point {
	short color;
public:
	Point(short c);
	Point();
	void run(); //������ ���������
};
//����������
Point::Point(short c) : color(c)
{
}
Point::Point() : Point(0xFFFFFF)
{
}
void Point::run()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
	//�������� ������� ���� �������
	CONSOLE_SCREEN_BUFFER_INFO inf;
	GetConsoleScreenBufferInfo(handle, &inf);
	int width = inf.srWindow.Right - inf.srWindow.Left + 1;
	int height = inf.srWindow.Bottom - inf.srWindow.Top + 1;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			COORD p = { j, i }; //���������� �����
			SetConsoleCursorPosition(handle, p);
			std::cout << '*';
			Sleep(1);
			system("CLS");
		}
}
int main()
{
	Point p1;//������� �����
	p1.run();
	Point p2(0x00FF00);//������ �����
	p2.run();
}
