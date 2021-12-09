#include <Windows.h>
class shape
{
protected:
	int x, y;//координаты центра фигуры
public:
	shape(int x, int y);
	shape();
	void setPos(int x, int y);
	virtual void draw(HDC dc) = 0;
};

class hexagon : public shape
{
private:
	int radius;
public:
	hexagon(int x, int y, int radius);
	hexagon();
	void setRadius(int new_radius);
	void draw(HDC dc);
};

