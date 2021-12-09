#include "geometrics.h"
#include <windows.h>
#include <iostream>
#include <math.h>
#include <algorithm>
void moveConsoleCursor(int x, int y);
//возвращает отрезок, принадлежащий треугольинку на данной высоте
//если такого нет, то NULL
Line* getLineWithEqualHeight(int y, Point *points, int points_num);

// реализация

//class Point
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}
Point::Point() : Point(0, 0)
{
}
int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}
void Point::move(int offset_x, int offset_y)
{
	this->x += offset_x;
	this->y += offset_y;
}
void Point::draw()
{
	moveConsoleCursor(x, y);
	std::cout << '*';
}
void Point::erase()
{
	moveConsoleCursor(x, y);
	std::cout << ' ';
}
void Point::rotateAboutPoint(float x1, float y1, double angle)
{
	x = (int)((x - x1) * cos(angle) -(y - y1) * sin(angle) + x1);
	y = (int)((x - x1) * sin(angle) + (y - y1) * cos(angle) + y1);
}
bool Point::operator==(Point p)
{
	return x == p.x && y == p.y;
}

//class Line
Line::Line(Point a, Point b) : Point(a), x2(b.x), y2(b.y)
{
}
Line::Line() : Line(Point(), Point())
{
}
void Line::move(int offset_x, int offset_y)
{
	Point::move(offset_x, offset_y); //передвигаем начало отрезка
	x2 += offset_x;//и конец
	y2 += offset_y;
}
void Line::draw()
{
	unsigned int size;
	Point *points = getAllPoints(&size);
	for (int i = 0; i < size; i++)
		points[i].draw();
	delete[] points;
}
void Line::erase()
{
	unsigned int size;
	Point *points = getAllPoints(&size);
	for (int i = 0; i < size; i++)
		points[i].erase();
	if(points)
		delete[] points;
}
//Находим все точки, принадлежащие отрезку по алгоритму Брезенхэма
Point* Line::getAllPoints(unsigned int* size)
{
	*size = 0;
	Point *points = NULL;
	//разница между началом и концом отрезка (по модулю)
	int difference_x = abs(x2 - x);
	int difference_y = abs(y2 - y);
	int error = 0.f; //ошибка нужна для того чтобы смещаться по y координате
	int delta_error = difference_y + 1;
	int current_y = y;
	int delta_y = y2 - y;
	if (delta_y > 0)
		delta_y = 1;
	else if (delta_y < 0)
		delta_y = -1;
	if (difference_x) //если отрезок не перпендикулярен горизонтальной стороне экрана
	{
		int delta_x = x2 - x;
		int sign = delta_x > 0 ? 1 : -1; //знак разницы между начальной x-координатой и конечной
		for (int current_x = x;
			 x2 < current_x || current_x < x2;
			 current_x += sign)
		{
			addPointToArray(current_x, current_y, &points, *size);
			(*size)++;
			error += delta_error;
			while (error >= difference_x + 1)
			{
				//если ошибка слишком большая, это значит что линия практически вертикальна
				//поэтому нужно для каждого x отрисовывать колонку точек
				current_y += delta_y;
				addPointToArray(current_x, current_y, &points, *size);
				(*size)++;
				error -= difference_x + 1;
			}
		}
	}
	else
		if (difference_y)
			for (int current_y = y;
				y2 < current_y || current_y < y2;
				current_y += delta_y)
			{
				addPointToArray(x, current_y, &points, *size);
				(*size)++;
			}
	return points;
}
void Line::addPointToArray(int x, int y, Point **arr, unsigned int array_size)
{
	Point point(x, y);
	Point *temp = *arr;
	*arr = new Point[array_size + 1];
	if(array_size)
		memcpy(*arr, temp, array_size * sizeof(Point));
	*(*arr + array_size) = point;
	if(temp)
		delete[] temp;
}
void Line::rotate(double angle)
{
	float center_x, center_y;
	getCenter(&center_x, &center_y);
	Point::rotateAboutPoint(center_x, center_y, angle);
	Point second_p(x2, y2); //конец отрезка
	second_p.rotateAboutPoint(center_x, center_y, angle);
	x2 = second_p.x;
	y2 = second_p.y;
}
void Line::getCenter(float *x, float *y)
{
	*x = (float)(this->x + x2) / 2.f;
	*y = (float)(this->y + y2) / 2.f;
}

//class Triangle
Triangle::Triangle(Point p1, Point p2, Point p3) : Line(p1, p2), x3(p3.x), 
	y3(p3.y), is_filled(false)
{
}
Triangle::Triangle() : Line(Point(), Point()), x3(0), y3(0)
{
}
void Triangle::move(int offset_x, int offset_y)
{
	Line::move(offset_x, offset_y);
	x3 += offset_x;
	y3 += offset_y;
}
void Triangle::draw()
{
	iterOverSides(true);
}
void Triangle::erase()
{
	iterOverSides(false);
}
void Triangle::iterOverSides(bool draw)
{
	//создаём 2 стороны треугольника
	Line B(Point(x2, y2), Point(x3, y3));
	Line C(Point(x, y), Point(x3, y3));
	//и отрисовываем, либо стираем
	if (draw)
	{
		Line::draw();
		B.draw();
		C.draw();
	}
	else
	{
		Line::erase();
		B.erase();
		C.erase();
	}
	if (is_filled) //если треугольник закрашенный
	{
		Point highest,lowest;
		if (y3 <= y2 && y3 <= y)
		{
			highest = Point(x3, y3);
			lowest = y2 >= y ? Point(x2, y2) : Point(x, y);
		}
		else if (y2 <= y && y2 <= y3)
		{ 
			highest = Point(x2, y2);
			lowest = y3 >= y ? Point(x3, y3) : Point(x, y);
		}
		else
		{
			highest = Point(x, y);
			lowest = y3 >= y2 ? Point(x3, y3) : Point(x2, y2);
		}
		int size;
		Point *all_points = getAllPoints(&size);
		fillFromPoint(highest, lowest, all_points, size, draw ? '*' : ' ');
		delete[] all_points;
	}
}
Point* Triangle::getAllPoints(int *size)
{
	//получаем точки всех сторон треугольинка
	Point *line1, *line2, *line3;
	unsigned int size1, size2, size3;
	line1 = Line::getAllPoints(&size1);
	Line B(Point(x2, y2), Point(x3, y3));
	Line C(Point(x, y), Point(x3, y3));
	line2 = B.getAllPoints(&size2);
	line3 = C.getAllPoints(&size3);
	*size = size1 + size2 + size3;
	Point *all_points = new Point[*size];
	memcpy(all_points, line1, size1 * sizeof(Point));
	memcpy(all_points + size1, line2, size2 * sizeof(Point));
	memcpy(all_points + size2, line3, size3 * sizeof(Point));
	delete[] line1;
	delete[] line2;
	delete[] line3;
	return all_points;
}
void Triangle::fillFromPoint(Point origin, Point lowest, Point *borders, int size, char ch_to_fill)
{
	Line* line;
	while ((line = getLineWithEqualHeight(origin.y++, borders, size)) != NULL)
	{
		ch_to_fill == '*' ? line->draw() : line->erase();
		delete line;
	}
}

void Triangle::rotate(double angle)
{
	float center_x, center_y;
	center_x = (float)(x + x2 + x3) / 3.f;
	center_y = (float)(y + y2 + y3) / 3.f;
	Point::rotateAboutPoint(center_x, center_y, angle);
	Point p2(x2, y2), p3(x3,y3);
	p2.rotateAboutPoint(center_x, center_y, angle);
	p3.rotateAboutPoint(center_x, center_y, angle);
	x2 = p2.x;
	y2 = p2.y;
	x3 = p3.x;
	y3 = p3.y;
}
void Triangle::fill()
{
	is_filled = true;
}

static void moveConsoleCursor(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD p = { x, y };
	SetConsoleCursorPosition(handle, p);
}

Line* getLineWithEqualHeight(int y, Point* points, int points_num)
{

	Line *line = NULL;
	Point *p1 = NULL, *p2 = NULL; //начало и конец отрезка
	for (int i = 0; i < points_num; i++)
	{
		if (points[i].getY() == y)
		{
			if (!p1)
				p1 = points + i;
			else
			{
				p2 = points + i;
				break;
			}
		}
	}
	if (p1 && p2)
	{
		line = new Line(*p1, *p2);
	}
	return line;
}