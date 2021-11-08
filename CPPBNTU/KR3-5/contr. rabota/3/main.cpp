#include "geometrics.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <Windows.h>
int main()
{
    Triangle triangle(Point(1, 0), Point(1, 10), Point(11, 10));
    Triangle triangle2;
    Line line1(Point(37, 10), Point(47, 10));
    Line line2 = line1;
    Point point(1, 1);
    triangle.move(5, 5);
    triangle2 = triangle;
    //Line line(Point(25, 5), Point(30, 28));
    triangle.fill();
    triangle.draw();
    triangle2.rotate(M_PI / 2 - 1); //поворот на 32 градуса
    triangle2.move(15, 0);
    triangle2.draw();
    point.draw();
    line1.draw();
    line2.rotate(M_PI / 4); // поворот на 45 градусов
    line2.draw();
    Sleep(10000);
    triangle.erase();
    triangle2.erase();
    line1.erase();
    line2.erase();
    point.erase();
    getchar();
    return 0;
}
