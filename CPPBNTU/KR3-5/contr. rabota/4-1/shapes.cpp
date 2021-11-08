#include "shapes.h"
//реализация

//class area
area::area(double w, double h) : weight(w), height(h)
{
}
area::area() : area(0., 0.)
{
}
void area::setar(double w, double h)
{
	weight = w;
	height = h;
}

//class rectangle
rectangle::rectangle(int w, int h) : area(w, h)
{
}
rectangle::rectangle() : area()
{
}
double rectangle::getar()
{
	return weight * height;
}

//class triangle
triangle::triangle(int w, int h) : area(w, h)
{
}
triangle::triangle() : area()
{
}
double triangle::getar()
{
	return weight * height / 2;
}

