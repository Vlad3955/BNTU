#include <iostream>
#include <Windows.h>
class Point
{
    int x, y;
public:
    Point(int a, int b) { x = a; y = b; };
    Point() : Point(0, 0) {  }
    int getX() { return x; }
    int getY() { return y; }
};
class Rect
{
    Point lt, rb;
public:
    Rect(Point a, Point b) : lt(a), rb(b) { }
    void draw()
    {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD p = { lt.getX(), lt.getY() };
        SetConsoleCursorPosition(handle, p);
        std::cout << static_cast<char>(218);//левый верхний угол
        p.Y = rb.getY();
        SetConsoleCursorPosition(handle, p);
        std::cout << static_cast<char>(192);//левый нижний угол
        p.X = rb.getX();
        SetConsoleCursorPosition(handle, p);
        std::cout << static_cast<char>(217);//правый нижний угол
        p.Y = lt.getY();
        SetConsoleCursorPosition(handle, p);
        std::cout << static_cast<char>(191);//левый верхний угол
        int width = rb.getX() - lt.getX();
        int height = rb.getY() - lt.getY();
        for (int i = 1; i < width; i++) //рисуем горизонтальные стороны
        {
            p.X = lt.getX() + i;
            p.Y = lt.getY();
            SetConsoleCursorPosition(handle, p);
            std::cout << static_cast<char>(196);
            p.Y = rb.getY();
            SetConsoleCursorPosition(handle, p);
            std::cout << static_cast<char>(196);
        }
        for (int i = 1; i < height; i++) //рисуем вертикальные стороны
        {
            p.X = lt.getX();
            p.Y = lt.getY() + i;
            SetConsoleCursorPosition(handle, p);
            std::cout << static_cast<char>(179);
            p.X = rb.getX();
            SetConsoleCursorPosition(handle, p);
            std::cout << static_cast<char>(179);
        }
    }
};

int main()
{
    Rect r(Point(2, 2), Point(50, 25));
    r.draw();
    getchar();
}
