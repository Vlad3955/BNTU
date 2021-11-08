#include <Windows.h>
#include "hexagon.h"
#include <iostream>
int main()
{
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
	int radius, number, distance; //радиус шестиугольников, количество и расстояние между ними
	//вводим радиус шестиугольников и их количество
	std::cout << "radius: "; std::cin >> radius;
	std::cout << "\nnumber: "; std::cin >> number;
	system("CLS");
	distance = radius * 2;
	shape **shapes = new shape*[number];
	//создаём ряд шестиугольников по введённым данным и отрисовываем
	for (int i = 0; i < number; i++)
	{
		shapes[i] = new hexagon(distance + i * distance, distance, radius);
		shapes[i]->draw(hDC);
	}
	//удаляём выделенную память
	for (int i = 0; i < number; i++)
		delete shapes[i];
	delete[] shapes;
	Sleep(10000);
    return 0;
}	
