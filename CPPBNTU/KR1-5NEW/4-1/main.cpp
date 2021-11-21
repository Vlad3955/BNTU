#include "shapes.h"
#include <iostream>
int main()
{
	int w1, h1, w2, h2;
	//вводим ширину и высоту прямоугольника 
	std::cin >> w1 >> h1;
	rectangle rect;
	rect.setar(w1, h1);
	std::cout << "Area of rectangle = " << rect.getar() << std::endl;
	//вводим основание треугольинка и высоту
	std::cin >> w2 >> h2;
	triangle t(w2, h2);
	std::cout << "Area of triangle = " << t.getar() << std::endl;
	return 0;
}