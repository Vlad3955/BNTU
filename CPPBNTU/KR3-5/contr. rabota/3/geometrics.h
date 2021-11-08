class Point
{
	friend class Line;
	friend class Triangle;
protected:
	int x;//координаты на экране
	int y;
public:
	Point(int x, int y);
	Point(); //конструктор по умолчанию
	int getX();
	int getY();
	virtual void move(int offset_x, int offset_y); //переместить
	virtual void draw(); //нарисовать
	virtual void erase(); //стереть
	//вращение точки относительно другой
	void rotateAboutPoint(float x1, float y1, double angle);
	bool operator==(Point p);
};

class Line : public Point
{
	friend class Triangle;
protected:
	int x2;
	int y2; //координаты конца отрезка (последняя точка не отрисовывается)
	//координаты начала отрезка - поля базового класса Point (x,y)

	void getCenter(float *x, float *y);
private:
	//генерирует массив точек, принадлежащих отрезку
	Point *getAllPoints(unsigned int *size); 
	//добавляет точку в массив
	void addPointToArray(int x, int y, Point **arr, unsigned int array_size);
public:
	Line(Point a, Point b);
	Line();
	virtual void move(int offset_x, int offset_y) override;
	virtual void draw() override;
	virtual void erase() override;
	virtual void rotate(double angle); 
};

class Triangle : public Line
{
private:
	//координаты третьей вершины треугольника
	int x3;
	int y3;
	//две остальные вершины - поля x,y базового класса Point и 
	//поле x2, y2 базового класса Line
	bool is_filled;//закрашен

	//отрисовка(если draw = true) и стирание сторон треугольинка
	void iterOverSides(bool draw);
	//начинает закраску треугольинка с точки(нужно для заливки) пока не дойдёт до высоты lowest
	void fillFromPoint(Point origin, Point lowest, Point *borders, int size, char ch_to_fill); 
	Point* getAllPoints(int *size);
public:
	Triangle(Point p1, Point p2, Point p3);
	Triangle();
	void move(int offset_x, int offset_y) override;
	void draw() override;
	void erase() override;
	void rotate(double angle) override;
	void fill(); //закрасить
};