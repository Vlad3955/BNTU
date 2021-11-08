#include "hexagon.h"
#include <Windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
//реализация

//class shape
shape::shape(int x, int y)
{
	this->x = x;
	this->y = y;
}
shape::shape() : shape(0,0)
{
}
void shape::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

//class hexagon
hexagon::hexagon(int x, int y, int radius) : shape(x,y)
{
	this->radius = radius;
}
hexagon::hexagon() : hexagon(0,0,0)
{
}
void hexagon::setRadius(int new_radius)
{
	radius = new_radius;
}
void hexagon::draw(HDC dc)
{
	double angle = M_PI / 3; //угол между диагоналями
	double half_a = angle / 2;
	POINT points[6];
	int side_height = (long)(radius * sin(half_a));//высота боковых углов
	int side_dist = (long)(radius * cos(half_a));//расстояние от центра до сторон
	points[0] = { x - side_dist, y + side_height };
	points[1] = { x, y + radius };
	points[2] = { x + side_dist, y + side_height };
	points[3] = { x + side_dist, y - side_height };
	points[4] = { x, y - radius };
	points[5] = { x - side_dist, y - side_height };
	SelectObject(dc, GetStockObject(WHITE_PEN));
	Polygon(dc, points, 6); //рисуем шестиугольник 
}